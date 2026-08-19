#include<stdio.h>
#include<stdlib.h>
int main()
{

    int isize=0,*arr=NULL,arrayBit=0,numberBit;
    
    printf("enter size of an array\n");
    scanf("%d",&isize);
    arr=malloc(isize*sizeof(int));
    numberBit=isize;
    for(int i=0;i<isize;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<isize;i++)
    {
        arrayBit=arrayBit^arr[i];
        numberBit=numberBit^i;
    }
   printf("missing number is %d\n",arrayBit^numberBit);

    return 0;
}