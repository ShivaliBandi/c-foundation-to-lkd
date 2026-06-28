#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_spinlock_t spinLock;
void *spinlockFunc(void *args)
{
    char *threadName=(char *)args;
    pthread_spin_lock(&spinLock);
    printf("threadNAme: %s\n",threadName);
    sleep(2);
    pthread_spin_unlock(&spinLock);
    return NULL;
}
int main()
{
    pthread_t thread[5];
    char *threadName[5]={"Thread1","Thread2","Thread3","Thread4","Thread5"};
    pthread_spin_init(&spinLock,PTHREAD_PROCESS_PRIVATE);
    for(int i=0;i<5;i++)
        pthread_create(&thread[i],NULL,spinlockFunc,threadName[i]);
    for(int i=0;i<5;i++)
        pthread_join(thread[i],NULL);
    pthread_spin_destroy(&spinLock);

    return 0;
}
/*
shivali-bandi@programmerInsane:~/Documents/c-foundation-to-lkd/multithreading$ gcc spinlock.c 
shivali-bandi@programmerInsane:~/Documents/c-foundation-to-lkd/multithreading$ ./a.out
threadNAme: Thread1
threadNAme: Thread4
threadNAme: Thread5
threadNAme: Thread2
threadNAme: Thread3
shivali-bandi@programmerInsane:~/Documents/c-foundation-to-lkd/multithreading$ 
*/