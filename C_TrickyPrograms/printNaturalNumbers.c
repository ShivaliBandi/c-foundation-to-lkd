/*
Print all natural numbers up to N without using a semi-colon. 
We use the idea of recursively calling the main function.
*/


#include<stdio.h>
int N=10;

int main()
{
    static int inum=0;
    if(printf("%d\n",inum) && inum++ < N && main() )

    return 0;
}