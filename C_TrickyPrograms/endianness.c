/*
Program to check endianness of the computer.


Little-endian:
78 56 34 12
↑
eobj.ch → 0x78


Big-endian:
12 34 56 78
↑
eobj.ch → 0x12


another solution 
// C program to find if machine is little
// endian or big endian.
#include <stdio.h>

int main() 
{
   unsigned int n = 1;
   char *c = (char*)&n;
   if (*c)    
       printf("LITTLE ENDIAN");
   else
       printf("BIG ENDIAN");
   return 0;
}
*/
#include<stdio.h>
#include<stdint.h>
union endianness
{
    uint32_t inum;
    unsigned char ch;
};
int main()
{
    union endianness eobj;
    eobj.inum=0x12345678;
    if(eobj.ch==0x78)
        printf("Little endianness\n");
    else
        printf("Big endianness\n");
}
