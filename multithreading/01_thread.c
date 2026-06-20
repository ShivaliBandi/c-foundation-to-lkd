#include<stdio.h>
#include<pthread.h>
void *demo(void *element)
{
    printf("Inside demo function\n");
    return NULL;
}
int main()
{
    pthread_t threadId;
    pthread_create(&threadId,NULL,demo,NULL);
    pthread_join(threadId,NULL);
    printf("Main exiting\n");

    return 0;
}