#include"header.h"
void swap(int *inum1,int *inum2)
{
    int itemp=*inum1;
    *inum1=*inum2;
    *inum2=itemp;
}
void Display(int *inum1,int *inum2)
{
    printf("inum1 = %d\tinum2 = %d\n",*inum1,*inum2);
}
int main()
{
    int inum1=0,inum2=0;
    printf("Enter 2 numbers that wants to be swapped:");
    scanf("%d%d",&inum1,&inum2);
    printf("Before swapping->");
    Display(&inum1,&inum2);
    swap(&inum1,&inum2);
    printf("After swapping->");
    Display(&inum1,&inum2);
    return 0;
}