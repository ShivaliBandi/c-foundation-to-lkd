#include"header.h"
int StringLength(char *str)
{
    int StringCount=0;
    while(*str!='\0')
    {
        StringCount++;
        str++;
    }
    return StringCount;
}
int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for(int icount=1;icount<argc;icount++)
        printf("String length of %s is %d\n",argv[icount],StringLength(argv[icount]));
    
    return 0;
}