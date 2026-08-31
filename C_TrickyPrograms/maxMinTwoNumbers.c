#include<stdio.h>
#include<stdlib.h>
/*
Program to find the Maximum and minimum of two numbers without using any loop or condition. 
The simplest trick is-
*/
int main()
{
    int inum1=10,inum2=200;
    printf("maxinum number is %d\n",(((inum1+inum2)+abs(inum1-inum2)))/2);
    printf("minimum number is %d\n",(((inum1+inum2)-abs(inum1-inum2)))/2);
    return 0;
}