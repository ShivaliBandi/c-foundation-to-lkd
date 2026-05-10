#include"header.h"
#define SIZE 5

int main()
{
    
    int iArr[SIZE],iElement=-1;
    bool iRet=false;
    printf("Enter %d integers\n", SIZE);
	for(int inum=0;inum<SIZE;inum++)
	{
		scanf("%d",&iArr[inum]);
		if(iArr[inum]<0)
		{
			printf("Invalid input: negative number\n");
			return -1;
		}
	}
    printf("Enter element you want to search in array\n");
    scanf("%d",&iElement);
    for(int inum=0;inum<SIZE;inum++)
    {
        if(iArr[inum]==iElement)
        {
            printf("Found element on %d index of an array\n",inum+1);
            iRet=true;
            break;
        }
    }
    if(iRet==false)
        printf("Element not found in array\n");
    return 0;
}