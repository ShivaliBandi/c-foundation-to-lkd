#include"header.h"
#define SIZE 10

int main()
{
    
    int iArr[SIZE],iElement=0,ifrequency=0;
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
            ifrequency++;
    }
    if(ifrequency==0)
        printf("Element not found in array\n");
    else
        printf("frequency of element->%d is %d\n",iElement,ifrequency);
    return 0;
}