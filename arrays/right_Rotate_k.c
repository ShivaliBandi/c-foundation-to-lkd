#include"header.h"
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

void reverse(int istart,int iend,int arr[])
{
    while(istart<iend)
    {
        int temp=arr[istart];
        arr[istart]=arr[iend];
        arr[iend]=temp;
        istart++;
        iend--;
    }
}
void right_Rotate_k(int isize,int arr[],int k)
{
    //this is reversal approach
    if(k>=isize)
        k=k%isize;
    if(k==0)
        return;
    k=isize-k;
    reverse(0,k-1,arr);
    reverse(k,isize-1,arr);
    reverse(0,isize-1,arr);
}
int main()
{
    int isize=0,*arr=NULL,k=0;
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
    printf("Before rotate array\n");
    DisplayArray(isize,arr);
    printf("enter k for number of time rotate array\n");
    
    scanf("%d",&k);
    if(k<0)
    {
        printf("ERROR:k is less then zero enter positive number");
        return -1;
    }
    //approach2_leftrotate_k(isize,arr,k);
    right_Rotate_k(isize,arr,k);
    printf("\nafter rotate\n");
    DisplayArray(isize,arr);
    free(arr);
    return 0;
}