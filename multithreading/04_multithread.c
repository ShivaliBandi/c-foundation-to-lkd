#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

void *thread_function(void *args)
{
    printf("inside thread functions %s\n",(char *)args);
    return NULL;
}
int main()
{
    
    pthread_t threadId1,threadId2,threadId3;
    pthread_create(&threadId1,NULL,thread_function,"thread1");
    pthread_create(&threadId2,NULL,thread_function,"thread2");
    pthread_create(&threadId3,NULL,thread_function,"thread3");

    pthread_join(threadId1,NULL);
    pthread_join(threadId2,NULL);
    pthread_join(threadId3,NULL);
    return 0;
}