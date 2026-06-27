#include <sys/mman.h>
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int *shared=mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);
    *shared=10;
    int fd=fork();
    if(fd==0)
    {
        sleep(3);
        printf("\nfrom child %d\n",*shared);
        exit(0);
    }
    else
    {
        *shared=100;
        printf("\nFrom parent\n");
        wait(NULL);
    }
    munmap(shared,sizeof(int));
    return 0;
}