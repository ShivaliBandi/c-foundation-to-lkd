#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
int count=0;
/*

If I ask:

Why isn't the answer 200000?

A strong answer is:

Both threads are updating the same shared variable count. 
The operation count++ is not atomic. Internally it performs read, modify, 
and write operations. When both threads interleave these operations, 
updates can be lost, resulting in a race condition.
*/
void *thread_function(void *args)
{
    for(int i=0;i<100000;i++)
        count++;
    return NULL;
}
int main()
{
    
    pthread_t threadId1,threadId2;
    pthread_create(&threadId1,NULL,thread_function,NULL);
    pthread_create(&threadId2,NULL,thread_function,NULL);
   
    pthread_join(threadId1,NULL);
    pthread_join(threadId2,NULL);
    printf("\nCount %d\n",count);
    return 0;
}