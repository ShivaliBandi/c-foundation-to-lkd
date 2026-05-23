#include"header.h"
void  StringCopy(const char *SourcString,char *DestinationString)
{
    char *desStr=DestinationString;
    for(char *str=SourcString;*str!='\0';str++,desStr++)
    {
        *desStr=*str;
    }
    *desStr='\0';
}
int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for(int icount=1;icount<argc;icount++)
    {
        char DestinationString[100];
        StringCopy(argv[icount],DestinationString);
        printf("Copied string %s\n",DestinationString);
    }
        
    return 0;
}