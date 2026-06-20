#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void *worker(void *arg)
{
    char *name = (char *)arg;

    printf("%s waiting for semaphore\n", name);

    sem_wait(&sem);

    printf("%s entered critical section\n", name);

    sleep(3);

    printf("%s leaving critical section\n", name);

    sem_post(&sem);

    return NULL;
}

int main()
{
    pthread_t t1, t2, t3, t4;

    sem_init(&sem, 0, 2);
    //IF HERE 3RD PARAMAETER IS PASSED 1 THEN ITS BINARY SEMAPHORE IT ACTS LIK MUTEX 
    pthread_create(&t1, NULL, worker, "Thread1");
    pthread_create(&t2, NULL, worker, "Thread2");
    pthread_create(&t3, NULL, worker, "Thread3");
    pthread_create(&t4, NULL, worker, "Thread4");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    sem_destroy(&sem);

    return 0;
}


/*
shivali-bandi@programmerInsane:~/Documents/c-foundation-to-lkd$ ./a.out
Thread1 waiting for semaphore
Thread1 entered critical section
Thread2 waiting for semaphore
Thread2 entered critical section
Thread3 waiting for semaphore
Thread4 waiting for semaphore
Thread2 leaving critical section
Thread1 leaving critical section
Thread3 entered critical section
Thread4 entered critical section
Thread3 leaving critical section
Thread4 leaving critical section
*/