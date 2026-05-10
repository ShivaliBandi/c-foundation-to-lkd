#include"header.h"
#define SIZE 5
int main()
{
	int iArr[SIZE];
    float favg=0;
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
	for(int inum=0;inum<SIZE;inum++)
	{
		favg+=iArr[inum];
	}
	favg/=SIZE;
	printf("Average element is %.2f\n",favg);
	return 0;
}
