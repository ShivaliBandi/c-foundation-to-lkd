#include <stdio.h>      // perror() (optional)
#include <fcntl.h>      // open(), O_RDONLY
#include <unistd.h>     // read(), write(), close()
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE (optional)
#include <string.h>
#include<errno.h>
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        printf("USAGE:used to cat the data of a file\n Syntax:executableFile {FILENAME}\n");
        return -1;
    }
    char buffer[10];

    memset(buffer,'\0',10);
    int fd=0,readcount=0;
    fd=open(argv[1],O_RDONLY);
    if(fd==-1)
    {
        perror("ERROR");
        return -1;
    }
       while((readcount=read(fd,buffer,10))>0)
            write(1,buffer,readcount);
        if(readcount==-1)
            perror("ERROR");
       
    close(fd);
    return 0;
}