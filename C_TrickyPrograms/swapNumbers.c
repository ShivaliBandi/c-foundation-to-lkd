#include<stdio.h>
/*
To Swap the values of two variables without using any extra variable.
*/
int main()
{

    unsigned int inum1,inum2;
    printf("Enter two numbers\n");
    scanf("%d%d",&inum1,&inum2);
    printf("before swapping\ninum1=%d\tinum2=%d\n",inum1,inum2);

    if(inum1==inum2)
        printf("both numbers are equal,swapping isnt needed\n");
    else
    {
        inum1=inum1+inum2;
        inum2=inum1-inum2;
        inum1=inum1-inum2;
        printf("after swapping\ninum1=%d\tinum2=%d\n",inum1,inum2);
    }
    return 0;
}