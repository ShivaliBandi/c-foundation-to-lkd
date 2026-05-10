#include"header.h"
#define SIZE 10

int main()
{
    
    int iArr[SIZE];
    printf("Enter %d integers\n", SIZE);
	for(int inum=0;inum<SIZE;inum++)
		scanf("%d",&iArr[inum]);
    printf("Array before reverse->");
    for(int inum=0;inum<SIZE;inum++)
        printf(" %d ",iArr[inum]);
    printf("\n");
    for(int istart=0,iend=SIZE-1;istart<iend;istart++,iend--)
    {
        int swap=iArr[istart];
        iArr[istart]=iArr[iend];
        iArr[iend]=swap;
    }
    printf("Array after reverse->");
    for(int inum=0;inum<SIZE;inum++)
        printf(" %d ",iArr[inum]);
    printf("\n");

    return 0;
}