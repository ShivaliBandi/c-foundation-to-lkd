#include"header.h"
int main()
{
	int *iArr=NULL,imax=0,isize=0;
    printf("enter size of array you want to allocate\n");
    scanf("%d",&isize);
    
    iArr=malloc(sizeof(int)*isize);
	for(int inum=0;inum<isize;inum++)
	{
		scanf("%d",&iArr[inum]);
		if(iArr[inum]<0)
		{
			printf("Invalid input: negative number\n");
			return -1;
		}
	}
    for(int i=0;i<isize;i++)
        printf("%d\n",iArr[i]);
    printf("\n\n--------------------------------------\n\n");
    int start=0,end=0;
	// while(end<isize && start!=isize)
    // {
    //     if(iArr[start]==0)
    //     {
    //         end=start+1;
    //         while (end<isize && iArr[end]==0 )            
    //             end++;
    //         if(end==isize)
    //             break;
    //         iArr[start]=iArr[end];
    //         iArr[end]=0;

    //     }
    //    start++;
    // }

    while(start<isize)
    {
        if(iArr[start]!=0)
        {
            int temp=iArr[start];
            iArr[start]=iArr[end];
            iArr[end]=temp;
            end++;
        }
        start++;
    }

    for(int i=0;i<isize;i++)
        printf("%d\n",iArr[i]);
	return 0;
}
