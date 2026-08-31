#include"header.h"
#define SIZE 5
// int *twoSum(int *arr,int isum)
// {
//     int *output=NULL;
//     output=malloc(sizeof(int)*2);
//     for(int i=0;i<SIZE-1;i++)
//     {
//         for(int j=i+1;j<SIZE;j++)
//         {
//             if(arr[i]+arr[j]==isum)
//             {
//                 output[0]=i;
//                 output[1]=j;
//                 return output;
//             }
//         }
//     }
//     free(output);
//     return NULL;

// }
int *twoSum(int *arr,int isum)
{
    int *iret;
    iret=malloc(2*sizeof(int));
    int istart=0,iend=SIZE-1;
    while(istart<iend)
    {
        if((arr[istart]+arr[iend])<isum)
            istart++;
        else if((arr[istart]+arr[iend])>isum)
            iend--;
        else
        {
            iret[0]=istart;
            iret[1]=iend;
            return iret;
        }
    
    }
    free(iret);
    return NULL;
}
int main()
{
    int arr[SIZE],isum=0;
    for(int inum=0;inum<SIZE;inum++)
        scanf("%d",&arr[inum]);
    printf("enter sum of 2 array\n");
    scanf("%d",&isum);
    int *output;
    output=twoSum(arr,isum);
    if(output!=NULL)
    {
        printf("Two sum indices are:%d %d\n",output[0],output[1]);
        free(output);
    }
}