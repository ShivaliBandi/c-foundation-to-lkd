#include"header.h"
int main()
{
    int inum=10;
    int *ptr=&inum;
    printf("inum value using pointer = %d\naddress of inum using pointer = %p\naddres of pointer itself = %p\n",*ptr,ptr,&ptr);
    return 0;
}