#include"header.h"
void swap(void *a,void *b,int isize)
{

    if(a==NULL || b==NULL)
        return ;
    char *pa=(char *)a;
    char *pb=(char *)b;
    char temp;
    for(int i=0;i<isize;i++)
    {
        temp=pa[i];
        pa[i]=pb[i];
        pb[i]=temp;
    }
}
int main()
{
    int a = 10;
    int b = 20;
    printf("before swap -> %d %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("after swap -> %d %d\n", a, b);
    char c1 = 'A';
    char c2 = 'B';
    printf("before swap -> %c %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("after swap -> %c %c\n", c1, c2);
    return 0;
}