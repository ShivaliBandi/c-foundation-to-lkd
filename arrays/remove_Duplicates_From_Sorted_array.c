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
int  RemoveDuplicate(int isize,int arr[])
{
    int *r=NULL,*w=NULL,icount=1;
    if (isize == 0)
        return 0;
    r=arr;
    w=arr+1;
    while(w!=arr+isize)
    {
        if(*r!=*w)
        {
            r++;
            *r=*w;
            icount++;
        }
        w++;
    }
    return icount;
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
    int iret=RemoveDuplicate(isize,arr);
    DisplayArray(iret,arr);
    free(arr);
    return 0;
}