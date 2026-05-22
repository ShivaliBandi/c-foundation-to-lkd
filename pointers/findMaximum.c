#include"header.h"
#define SIZE 5
void Display_Array(int *arr)
{
   for(int *ptr=arr;ptr<arr+SIZE;ptr++)
        printf("ptr(%p)->%d\n",ptr,*ptr);
   
       
}
void Accept_Array(int *arr)
{
    for(int inum=0;inum<SIZE;inum++)
        scanf("%d",&arr[inum]);
}
int findMaximum(int *arr)
{
    int imax=*arr;
    for(int *ptr=arr+1;ptr<arr+SIZE;ptr++)
        if(imax<*ptr)
            imax=*ptr;

    return imax;
}
int main()
{
    int arr[SIZE];
    Accept_Array(arr);
    Display_Array(arr);
    printf("Maximum element from array is %d \n",findMaximum(arr));
    return 0;
}