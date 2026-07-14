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
void approach1_leftrotate_k(int isize,int arr[],int k)
{
    
    if(k>=isize)
        k=k%isize;
    for(int j=0;j<k;j++)
    {
        int temp=arr[0];
        for(int i=0;i<isize-1;i++)
            arr[i]=arr[i+1];
        arr[isize-1]=temp;

    }
        
}
void approach2_leftrotate_k(int isize,int arr[],int k)
{
    int *iret=NULL;
    if(k>=isize)
        k=k%isize;
    iret=malloc(sizeof(int)*isize);
    if(iret == NULL)
    {
        printf("Memory Allocation Failed\n");
        return ;
    }
    //first part
    for(int i=k,j=0;i<isize;i++,j++)
        iret[j]=arr[i];
    //second part
    for(int i=0,j=isize-k;i<k;i++,j++)
        iret[j]=arr[i];
    for(int i=0;i<isize;i++)
        arr[i]=iret[i];
    free(iret);
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
void approach3_leftRotate_k(int isize,int arr[],int k)
{
    //this is reversal approach
    if(k>=isize)
        k=k%isize;
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
   // approach1_leftrotate_k(isize,arr,k);
    //approach2_leftrotate_k(isize,arr,k);
    approach3_leftRotate_k(isize,arr,k);
    printf("\nafter rotate\n");
    DisplayArray(isize,arr);
    free(arr);
    return 0;
}