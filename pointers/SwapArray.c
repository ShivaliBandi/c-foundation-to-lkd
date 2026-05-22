#include"header.h"
#define SIZE 5
void SwapElements(int *inum1,int *inum2)
{
    int itemp=*inum1;
    *inum1=*inum2;
    *inum2=itemp;
}
void Display_Array(int *arr)
{
   for(int *ptr=arr;ptr<arr+SIZE;ptr++)
        printf("ptr(%p)->%d\n",ptr,*ptr);
   
       
}
void Accept_Array(int *arr)
{
    for(int *ptr=arr;ptr<arr+SIZE;ptr++)
        scanf("%d",ptr);
}
void ReverseArray(int *arr)
{
    for(int *StartPtr=arr,*EndPtr=arr+(SIZE-1);StartPtr<EndPtr;StartPtr++,EndPtr--)
        SwapElements(StartPtr,EndPtr);
}
int main()
{
    int arr[SIZE];
    Accept_Array(arr);
    printf("Before Swap\n");
    Display_Array(arr);
    ReverseArray(arr);
    printf("After Swap\n");
    Display_Array(arr);

    return 0;
}