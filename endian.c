#include<stdio.h>
union demo{
    int i;
    char c[4];
};
int main()
{

    union demo dobj;
    dobj.i=0x12345678;
    printf("%c",dobj.c[0]);//this code prints x the asci of x is 0x78
    printf("%x",(unsigned char)dobj.c[0]);//this prints the hexadecimal x78
    return 0;
}
