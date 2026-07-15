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
bool isSorted(int isize,int arr[])
{
    bool result=true;
    for(int i=0;i<isize-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            result=false;
            break;
        }
            
        
    }
    return result;
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
    (isSorted(isize,arr)==1)?printf("Is sorted array\n"):printf("Not sorted array\n");
    free(arr);
    return 0;
}