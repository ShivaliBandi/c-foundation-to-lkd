#include<stdio.h>
#include<pthread.h>
#include<stdatomic.h>

atomic_int counter=0;

void *increment()
{
    for(int i=0;i<100000;i++)
        atomic_fetch_add(&counter,1);
    return NULL;
}

int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,increment,NULL);
    pthread_create(&t2,NULL,increment,NULL);


    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Final counter %d \n",atomic_load(&counter));
    return 0;
}


/*
gcc -std=c11 -Wall -Wextra -pthread multithreading/atomic.c -o atomic_counter


1. gcc
Runs the GNU Compiler Collection's C compiler.
It translates your C source code into an executable program.


2. -std=c11
Tells GCC to compile using the C11 language standard.
We use C11 because it introduced standard atomic types and operations through <stdatomic.h>.
Without this flag, GCC may use a different default language standard.


3. -Wall
Enables a broad collection of useful compiler warnings.
For example, GCC may warn about certain suspicious code patterns or unused variables.


4. -Wextra
Enables additional warnings beyond those included in -Wall.
Interview tip: Warnings help you identify potential bugs before running the program. They are not all errors, but you should investigate them.


5. -pthread
Enables the appropriate compiler and linker settings for POSIX threads.
We need this because our program uses functions such as pthread_create() and pthread_join().
It is preferable to use -pthread rather than only -lpthread, because -pthread can also configure compilation appropriately for the platform.

*/