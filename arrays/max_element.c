#include"header.h"
#define SIZE 5
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
	imax=iArr[0];
	for(int inum=1;inum<SIZE;inum++)
	{
		if(iArr[inum]>imax)
			imax=iArr[inum];
	}
	printf("maximum element is %d\n",imax);
	return 0;
}
