#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
pthread_mutex_t lock;
pthread_cond_t cond;

int turn = 1;
void *thread_function(void *args)
{
    int my_turn = *(int *)args;

    pthread_mutex_lock(&lock);

    while(turn != my_turn)
    {
        pthread_cond_wait(&cond, &lock);
    }

    printf("inside thread %d\n", my_turn);

    turn++;

    pthread_cond_broadcast(&cond);

    pthread_mutex_unlock(&lock);

    return NULL;
}
int main()
{
    
    
int t1 = 1;
int t2 = 2;
int t3 = 3;
pthread_t threadId1,threadId2,threadId3;
pthread_mutex_init(&lock, NULL);
pthread_cond_init(&cond, NULL);

pthread_create(&threadId1, NULL, thread_function, &t1);
pthread_create(&threadId2, NULL, thread_function, &t2);
pthread_create(&threadId3, NULL, thread_function, &t3);

pthread_join(threadId1, NULL);
pthread_join(threadId2, NULL);
pthread_join(threadId3, NULL);
return 0;
}