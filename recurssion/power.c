#include<stdio.h>
// int power(int x,int n)
// {
//     if(n==0)
//         return 1;
    
//     return x*power(x,n-1);
    
    
// }

int power(int x,int n)
{
    if(n==0)
        return 1;
    int  half=power(x,n/2);
    if(n%2==0)
        return half*half;
    else
        return x*half*half;
    
}
int main()
{
    int x=0,n=0,half;
    printf("Enter x and n where it is x^n\n");
    scanf("%d%d",&x,&n);
   
    printf("%d\n",power(x,n));
    return 0;
}