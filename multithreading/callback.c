
/*
 * Problem: Thread-safe callback registration and event firing.
 *
 * Compile:
 *   gcc -std=c11 -Wall -Wextra -pthread callback_event.c -o callback_event
 *
 * Run:
 *   ./callback_event
 *
 * Design:
 *   1. reg_cb() registers a callback.
 *   2. event_fired() executes callbacks registered before the event.
 *   3. Callbacks registered while the event is firing go into a pending queue.
 *   4. Callbacks registered after the event finishes execute immediately.
 */

#include <stdio.h>       // printf()
#include <pthread.h>     // pthread mutexes, condition variables and thread IDs

#define MAX_CALLBACKS 100 // Maximum callbacks allowed in each queue

/*
 * A callback is a pointer to a function that:
 *   - takes no arguments
 *   - returns nothing
 *
 * Example:
 *   void callback_A(void);
 *
 *   Callback cb = callback_A;
 *   cb(); // Calls callback_A()
 */
typedef void (*Callback)(void);

/*
 * The event has three possible states:
 *
 * IDLE     -> The event has not started firing.
 * FIRING   -> The event is currently executing callbacks.
 * FINISHED -> The event has completed.
 */
enum EventState {
    IDLE,
    FIRING,
    FINISHED
};

/*
 * Mutex protects all shared state below:
 *   - state
 *   - callbacks[] and callback_count
 *   - pending[] and pending_count
 *   - event_thread
 *
 * A thread must lock this mutex before reading or modifying
 * these shared variables.
 */
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

/*
 * Condition variable used to notify waiting registration threads
 * when the event has finished.
 *
 * pthread_cond_wait() temporarily releases mtx while waiting,
 * then reacquires mtx before returning.
 */
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

/* Current state of the one-shot event. Initially, it has not fired. */
static enum EventState state = IDLE;

/*
 * Main callback queue:
 * Callbacks registered while state == IDLE are stored here.
 */
static Callback callbacks[MAX_CALLBACKS];
static int callback_count = 0;

/*
 * Pending callback queue:
 * Callbacks registered while state == FIRING are stored here.
 * They execute after the current batch finishes.
 */
static Callback pending[MAX_CALLBACKS];
static int pending_count = 0;

/*
 * Thread that called event_fired().
 *
 * This lets reg_cb() identify a callback registering another callback
 * from inside the event thread itself.
 *
 * That thread must NOT wait for the event to finish, because it is
 * itself responsible for finishing the event.
 */
static pthread_t event_thread;


/*
 * reg_cb()
 *
 * Registers a callback according to the current event state.
 *
 * Returns:
 *   0  -> registration accepted / callback handled
 *  -1  -> invalid callback or queue capacity exceeded
 */
int reg_cb(Callback cb)
{
    /* Reject a null function pointer. */
    if (cb == NULL) {
        return -1;
    }

    /*
     * Lock before examining state or changing either queue.
     * This prevents two threads from modifying shared data
     * simultaneously.
     */
    pthread_mutex_lock(&mtx);

    /*
     * CASE 1: The event has already finished.
     *
     * There is no future event execution in this one-shot design,
     * so execute this newly registered callback immediately.
     *
     * Unlock FIRST: never call user callback code while holding mtx.
     */
    if (state == FINISHED) {
        pthread_mutex_unlock(&mtx);

        cb();                 // Execute callback outside the mutex
        return 0;
    }

    /*
     * CASE 2: The event has not started.
     *
     * Save the callback in the initial callback queue.
     * event_fired() will execute it later.
     */
    if (state == IDLE) {
        /* Prevent writing beyond the array's capacity. */
        if (callback_count >= MAX_CALLBACKS) {
            pthread_mutex_unlock(&mtx);
            return -1;
        }

        callbacks[callback_count] = cb; // Store function pointer
        callback_count++;               // Increase number of callbacks

        pthread_mutex_unlock(&mtx);
        return 0;
    }

    /*
     * CASE 3: The event is currently firing.
     *
     * Do not add the new callback to the batch currently executing.
     * Put it into pending[] so it executes in a later batch.
     */
    if (state == FIRING) {
        /* Prevent writing beyond the pending queue's capacity. */
        if (pending_count >= MAX_CALLBACKS) {
            pthread_mutex_unlock(&mtx);
            return -1;
        }

        pending[pending_count] = cb; // Store callback for a later batch
        pending_count++;             // Increase pending queue count

        /*
         * Is this call coming directly from the event thread?
         *
         * For example:
         *   event_fired() calls callback_A()
         *   callback_A() calls reg_cb(callback_B)
         *
         * In that situation, return immediately.
         *
         * If we waited for the event to finish here, we would
         * deadlock: the event cannot finish until callback_A returns.
         */
        if (pthread_equal(pthread_self(), event_thread)) {
            pthread_mutex_unlock(&mtx);
            return 0;
        }

        /*
         * Otherwise, this is a different thread registering a callback.
         *
         * It can wait until the event has finished. The callback has
         * already been queued and will be processed by event_fired().
         *
         * Use WHILE, not IF, because condition-variable wakeups do not
         * themselves guarantee that the condition is true.
         *
         * pthread_cond_wait() releases mtx while waiting and reacquires
         * it before returning.
         */
        while (state == FIRING) {
            pthread_cond_wait(&cond, &mtx);
        }

        pthread_mutex_unlock(&mtx);
        return 0;
    }

    /*
     * Defensive fallback. The three states above should cover all
     * valid states in this implementation.
     */
    pthread_mutex_unlock(&mtx);
    return -1;
}


/*
 * event_fired()
 *
 * Fires the event once.
 *
 * It executes:
 *   1. Callbacks registered before the event started.
 *   2. Callbacks added to the pending queue while it was firing.
 *   3. Any further callbacks added by those pending callbacks.
 *
 * The loop stops when no pending callbacks remain.
 */
void event_fired(void)
{
    /*
     * A local batch holds callbacks to execute now.
     *
     * This is a local array, separate from the shared queues.
     * It allows callbacks to execute without holding mtx.
     */
    Callback batch[MAX_CALLBACKS];

    int batch_count = 0; // Number of callbacks in the current batch

    /* Lock before checking or changing event state. */
    pthread_mutex_lock(&mtx);

    /*
     * This is a one-shot event.
     * If it has already started or finished, do not fire it again.
     */
    if (state != IDLE) {
        pthread_mutex_unlock(&mtx);
        return;
    }

    /* Mark the event as active. */
    state = FIRING;

    /*
     * Record which thread is running this event.
     * reg_cb() uses this to avoid waiting on itself.
     */
    event_thread = pthread_self();

    /*
     * Copy callbacks registered before the event started into batch.
     * The event thread now owns this local snapshot for execution.
     */
    batch_count = callback_count;

    for (int i = 0; i < batch_count; i++) {
        batch[i] = callbacks[i];
    }

    /*
     * The original callbacks are now in the local batch.
     * Reset the shared queue count so new registrations are handled
     * according to state == FIRING and go into pending[].
     */
    callback_count = 0;

    /* Release the mutex before running user callback code. */
    pthread_mutex_unlock(&mtx);

    /*
     * Process batches until no pending callbacks remain.
     *
     * A callback in this batch may call reg_cb(), adding more work
     * to pending[]. The next iteration will execute that work.
     */
    for (;;)
    {

        /*
         * Execute the current batch.
         *
         * IMPORTANT:
         * No mutex is held here. A callback can safely call reg_cb()
         * without attempting to lock a mutex already held by this code.
         */
        for (int i = 0; i < batch_count; i++) {
            batch[i](); // Invoke the callback function
        }

        /*
         * All callbacks in this batch have completed.
         * Lock before inspecting the shared pending queue.
         */
        pthread_mutex_lock(&mtx);

        /*
         * If no callback was registered during the last batch,
         * the event has completed.
         */
        if (pending_count == 0) {
            state = FINISHED; // Publish the final event state

            /*
             * Wake all external registration threads that are waiting
             * for state to stop being FIRING.
             *
             * The state change and broadcast happen while holding mtx.
             */
            pthread_cond_broadcast(&cond);

            pthread_mutex_unlock(&mtx);
            return; // Event is completely finished
        }

        /*
         * Pending callbacks exist.
         *
         * Copy them into the local batch so they can execute without
         * holding the shared mutex.
         */
        batch_count = pending_count;

        for (int i = 0; i < batch_count; i++) {
            batch[i] = pending[i];
        }

        /*
         * The pending callbacks have been moved into the local batch.
         * Clear the pending queue for callbacks registered during
         * the next batch.
         */
        pending_count = 0;

        /* Release the mutex before executing the next batch. */
        pthread_mutex_unlock(&mtx);

        /*
         * Control returns to the start of the loop.
         * The callbacks just copied into batch[] execute next.
         */
    }
}


/* ---------------- Example callbacks used by main() ---------------- */

/* This callback is registered before the event fires. */
void callback_A(void)
{
    printf("Callback A: started\n");

    /*
     * callback_A() registers callback_B() while the event is firing.
     *
     * Because callback_A() runs on the event thread, reg_cb() queues
     * callback_B() in pending[] and returns without waiting.
     */
    if (reg_cb(callback_B) != 0) {
        printf("Callback A: failed to register callback B\n");
    }

    printf("Callback A: finished\n");
}

/* This callback is registered from inside callback_A(). */
void callback_B(void)
{
    printf("Callback B: executed from the pending queue\n");
}

/* This callback will be registered after the event has finished. */
void callback_C(void)
{
    printf("Callback C: executed immediately after registration\n");
}


/* ------------------------------ main() ------------------------------ */

int main(void)
{
    printf("1. Register callback A before firing the event\n");

    /*
     * At this moment:
     *   state == IDLE
     *
     * Therefore reg_cb(callback_A) stores callback_A in callbacks[].
     * It does NOT execute callback_A yet.
     */
    if (reg_cb(callback_A) != 0) {
        fprintf(stderr, "Failed to register callback A\n");
        return 1;
    }

    printf("\n2. Fire the event\n");

    /*
     * event_fired() changes the state from IDLE to FIRING.
     *
     * It copies callback_A into a local batch and executes it.
     *
     * callback_A registers callback_B:
     *   - state is FIRING
     *   - callback_B goes into pending[]
     *   - callback_A continues and returns
     *
     * The event loop then picks up callback_B and executes it.
     *
     * When pending[] becomes empty, the event changes to FINISHED.
     * event_fired() then returns to main().
     */
    event_fired();

    printf("\n3. Register callback C after the event has finished\n");

    /*
     * At this moment:
     *   state == FINISHED
     *
     * Therefore reg_cb(callback_C) unlocks the mutex and calls
     * callback_C() immediately.
     */
    if (reg_cb(callback_C) != 0) {
        fprintf(stderr, "Failed to register callback C\n");
        return 1;
    }

    printf("\n4. main() is complete\n");

    return 0; // Report successful program completion
}
