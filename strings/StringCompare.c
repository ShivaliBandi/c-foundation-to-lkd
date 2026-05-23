#include"header.h"
int StringCompare(const char *str1,const char *str2)
{
    int iret=0;
    if(strlen(str1)==strlen(str2))
    {
        for(char *ptr1=str1,*ptr2=str2;*ptr1!='\0';ptr1++,ptr2++)
        {
            if(*ptr1!=*ptr2)
            {
                iret=-1;
                break;
            }
        }
        
    }
    else
        iret=-1;
    return iret;
    
}
int main(int argc,char *argv[])
{
    if(argc !=3)
    {
        fprintf(stderr,"Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int iRet=StringCompare(argv[1],argv[2]);
    if(iRet!=0)
        printf("Both string are not same\n");
    else
        printf("Both string are same\n");
    return 0;
}