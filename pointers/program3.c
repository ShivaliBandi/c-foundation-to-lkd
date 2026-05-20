#include"header.h"
#define SIZE 5
void Display_Array(int arr[])
{
   for(int inum=0;inum<SIZE;inum++)
   {
        printf("arr[%d]->%d\t*(arr+%d)->%d\n",inum,arr[inum],inum,*(arr+inum));
        printf("&arr[%d] = %p\t(arr+%d) = %p\n",inum,&arr[inum],inum,(arr+inum));
   }
       
}
void Accept_Array(int arr[])
{
    for(int inum=0;inum<SIZE;inum++)
        scanf("%d",&arr[inum]);
}
int main()
{
    int arr[SIZE];
    Accept_Array(arr);
    Display_Array(arr);

    return 0;
}