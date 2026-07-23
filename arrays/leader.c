#include"header.h"
#define SIZE 6
int main()
{
	int iArr[SIZE],imax=0;
	printf("Enter %d intergers\n", SIZE);
	for(int inum=0;inum<SIZE;inum++)
	{
		scanf("%d",&iArr[inum]);
		if(iArr[inum]<0)
		{
			printf("Invalid input: negative number\n");
			return -1;
		}
	}
	imax=iArr[SIZE-1];
    printf("%d ",imax);
	for(int inum=SIZE-2;inum>=0;inum--)
	{
		if(iArr[inum]>imax)
        {
            printf("%d ",iArr[inum]);
            imax=iArr[inum];
            
        }
		
	}
	
	return 0;
}
