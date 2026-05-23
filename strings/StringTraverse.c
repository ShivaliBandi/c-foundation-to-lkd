#include"header.h"
int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
        
    
    char *str=argv[1];
    
    while(*str!='\0')
    {
        printf("%c",*str);
        str++;
    }
       
    return 0;
}