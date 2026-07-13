#include"header.h"
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
    for(int i=0;i<isize;i++)
        scanf("%d",&arr[i]);

    printf("Before rotate array\n");

    for(int i=0;i<isize;i++)
        printf("%d ",arr[i]);

    int temp=arr[isize-1];

    for(int i=isize-1;i>0;i--)
        arr[i]=arr[i-1];

    arr[0]=temp;
    
    printf("\nafter rotate\n");
    for(int i=0;i<isize;i++)
        printf("%d ",arr[i]);

    return 0;
}