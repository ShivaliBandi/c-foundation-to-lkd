/*
Print the maximum value of an unsigned int using One's Complement (~) Operator in C. 
Here is a trick to find the maximum value of an unsigned int using one's complement operator:
*/
// C program to print maximum value of
// unsigned int.
#include<stdio.h>

int main()
{
   unsigned int max;
   max = 0;
   max = ~max;
   printf("Max value : %u ",  max);
  return 0;
}