#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct demo{
    int i;
    char c[];
};
int main()
{
    struct demo dobj;
    printf("%ld\n",sizeof(dobj));// give 4byte 
    char s[]="Shivali";
    struct demo *d=malloc(sizeof(struct demo) + strlen(s) + 1);
     printf("%ld\n",sizeof(d));//8

    return 0;
}