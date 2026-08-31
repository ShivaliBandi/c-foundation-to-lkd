/*
To find the sum of two integers without using '+' operator. 
This is a very easy mathematics trick. 
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int inum1=10,inum2=200;
    int isum=-(-inum1-inum2);
    printf("addition of 2 number is %d\n",isum);
    return 0;
}