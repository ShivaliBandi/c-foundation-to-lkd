#include<stdlib.h>
#include<stdio.h>
void reverse(int arr[],int start,int end)
{
    if(start>=end)
        return;
    int temp;
    temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;

    reverse(arr,start+1,end-1);

   
}
void acceptElements(int isize,int arr[])
{
    for(int i=0;i<isize;i++)
        scanf("%d",&arr[i]);
}
void DisplayArray(int isize,int arr[])
{
     for(int i=0;i<isize;i++)
        printf("%d ",arr[i]);
    printf("\n");


}
int main()
{
    int isize=0,*arr=NULL;
    printf("Enter size of an array\n");
    scanf("%d",&isize);
    if(isize<2)
    {
        printf("ERROR:Array size is invalid\n");
        return -1;
    }
    arr=malloc(sizeof(int)*isize);
    if(arr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return -1;
    }
    acceptElements(isize,arr);
    printf("Before reverse\n");
    DisplayArray(isize,arr);

    printf("After Reverse\n");
    reverse(arr,0,isize/2);
    DisplayArray(isize,arr);
    free(arr);
    return 0;
}