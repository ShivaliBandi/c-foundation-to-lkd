#include<stdio.h>
#include<stdlib.h>
int add(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return (a>b)?a-b:b-a;
}
int multiply(int a, int b)
{
    return a*b;
}
int divide(int a,int b)
{
    return (a>b)?a/b:b/a;  
}
int calc(int a,int b,int (*ptr)(int a,int b))
{
    return (*ptr)( a, b);
}

int main()
{
 //   printf("Addition -> %d\n",calc(10,20,add));
 //   printf("subtraction -> %d\n",calc(130,123,sub));
//    printf("multiplication -> %d\n",calc(10,20,multiply));
 //   printf("division -> %d\n",calc(10,20,divide));
 //   printf("subtraction -> %d\n",calc(10,2330,sub));
    int (*operations[4])(int,int)={add,sub,divide,multiply};
    for(int i=0;i<4;i++)
        printf("%d\n",operations[i](10,20));
    return 0;
}