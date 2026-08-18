/*
To check if two numbers are equal without using arithmetic operators or comparison operators. 
The simplest solution for this is using the Bitwise XOR operator (^). 
We know that for two equal numbers XOR operator returns 0. We will use the XOR operator to solve this problem
*/

#include<stdio.h>
int main()
{
    unsigned int inum1,inum2;
    printf("Enter two numbers\n");
    scanf("%d%d",&inum1,&inum2);
    if((inum1^inum2)==0)
        printf("Both numbers are equal\n");
    else
        printf("Both numbers are not equal\n");        

    return 0;
}