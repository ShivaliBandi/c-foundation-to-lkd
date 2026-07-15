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
int Find_Missing_Num(int isize,int arr[])
{
    int xor=0,xorArr=0,j=1;
    for(int i=0;i<isize;i++,j++)
    {
        xor^=j;
        xorArr^=arr[i];
    }
    xor^=j;
    return xor^xorArr;
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
    printf("Missing number is %d\n",Find_Missing_Num(isize,arr));
    free(arr);
    return 0;
}