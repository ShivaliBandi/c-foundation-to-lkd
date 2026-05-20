#include"header.h"
void Display(int arr[],int isize)
{
    for(int inum=0;inum<isize;inum++)
        printf("arr[%d] = %d\n", inum, arr[inum]);
}
int FindMaximum(int arr[],int isize)
{
    int imax=arr[0];
    for(int inum=1;inum<isize;inum++)
	{
		if(arr[inum]>imax)
			imax=arr[inum];
	}
    return imax;
}
int FindMinimum(int iArr[],int SIZE)
{
    int imin=iArr[0];
	for(int inum=1;inum<SIZE;inum++)
	{
		if(iArr[inum]<imin)
			imin=iArr[inum];
	}
    return imin;
}
void ReverseArray(int iArr[],int SIZE)
{

    for(int istart=0,iend=SIZE-1;istart<iend;istart++,iend--)
    {
        int swap=iArr[istart];
        iArr[istart]=iArr[iend];
        iArr[iend]=swap;
    }
    Display(iArr,SIZE);
}
int main()
{
    int isize=5,arr[isize];
    for(int inum=0;inum<isize;inum++)
        scanf("%d",&arr[inum]);
    //printf("Display array elements\n");
    //Display(arr,isize);
    //printf("maximum element %d\n",FindMaximum(arr,isize));
    //printf("minimum element %d\n",FindMinimum(arr,isize));
    ReverseArray(arr,isize);
    return 0;
}