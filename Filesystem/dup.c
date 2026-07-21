#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main()
{

    int fd1,fd2;
    char ch;
    fd1=open("demo.txt",O_RDONLY);
    if(fd1==-1)
    {
        perror("open");
        return EXIT_FAILURE;   
    }
    if(read(fd1,&ch,1)<0)
    {
        perror("ERROR");
        return -1;
    }
    printf("fd1-> %c \n",ch);
   
    fd2=dup(fd1);
    close(fd1);

    if(fd2==-1)
    {
        perror("dup");
        return EXIT_FAILURE;
    }
    if(read(fd2,&ch,1)<0)
    {
        perror("ERROR");
        return -1;
    }
    printf("fd2-> %c \n",ch);
    
    close(fd2);
    return 0;
}


/*

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main()
{

    int fd1,fd2;
    char ch;
    fd1=open("demo.txt",O_RDONLY);
    if(fd1==-1)
    {
        perror("open");
        return EXIT_FAILURE;   
    }
    if(read(fd1,&ch,1)<0)
    {
        perror("ERROR");
        return -1;
    }
    printf("fd1-> %c \n",ch);


    fd2=dup(fd1);

    if(fd2==-1)
    {
        perror("dup");
        return EXIT_FAILURE;
    }
    if(read(fd2,&ch,1)<0)
    {
        perror("ERROR");
        return -1;
    }
    printf("fd2-> %c \n",ch);
    close(fd1);
    close(fd2);
    return 0;
}
*/