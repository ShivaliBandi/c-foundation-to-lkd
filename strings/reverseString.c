#include"header.h"
void  reverseString(char *str)
{
    char *start=str,*end=str+(strlen(str)-1),temp;
    while(start<end)
    {
        temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}
int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *str=argv[1];
    printf("before reverse %s\n",str);
    reverseString(str);
    printf("after reverse %s\n",str);
        
    return 0;
}