#include"header.h"
#define SIZE 5
void Display_Array(int arr[])
{
   for(int *ptr=arr;ptr<arr+SIZE;ptr++)
        printf("ptr(%p)->%d\n",ptr,*ptr);
   
       
}
void Accept_Array(int arr[])
{
    for(int inum=0;inum<SIZE;inum++)
        scanf("%d",&arr[inum]);
}
void Multiply_Elements(int arr[])
{
    for(int *ptr=arr;ptr<arr+SIZE;ptr++)
    {
        *ptr=*ptr*2;
    }
}
int main()
{
    int arr[SIZE];
    Accept_Array(arr);
    printf("before changes element values:\n");
    Display_Array(arr);
    Multiply_Elements(arr);
    printf("after changes element values:\n");
    Display_Array(arr);
    return 0;
}