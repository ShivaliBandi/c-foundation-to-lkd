#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t lock;
pthread_cond_t not_empty;
pthread_cond_t not_full;

void *producer(void *arg)
{
    int item = *(int *)arg;

    pthread_mutex_lock(&lock);

    while (count == SIZE)
    {
        pthread_cond_wait(&not_full, &lock);
    }

    buffer[in] = item;

    printf("Produced -> %d at index %d\n", item, in);

    in = (in + 1) % SIZE;
    count++;

    pthread_cond_signal(&not_empty);

    pthread_mutex_unlock(&lock);

    return NULL;
}

void *consumer(void *arg)
{
    pthread_mutex_lock(&lock);

    while (count == 0)
    {
        pthread_cond_wait(&not_empty, &lock);
    }

    int item = buffer[out];

    printf("Consumed -> %d from index %d\n", item, out);

    out = (out + 1) % SIZE;
    count--;

    pthread_cond_signal(&not_full);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t producers[5];
    pthread_t consumers[5];

    int items[5];

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);

    for (int i = 0; i < 5; i++)
    {
        items[i] = (i + 1) * 10;

        pthread_create(&producers[i],
                       NULL,
                       producer,
                       &items[i]);
    }

    sleep(1);

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&consumers[i],
                       NULL,
                       consumer,
                       NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(consumers[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);

    return 0;
}