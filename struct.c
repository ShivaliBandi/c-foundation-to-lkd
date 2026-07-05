#include<stdio.h>
struct demo
{
    int inum;
    double dnum;
    char c;

};//24

struct demo1
{
    int inum;
    char c;
    double dnum;
    

};//24

int main()
{
    struct demo dobj;
    printf("size of struct demo -> %ld\n",sizeof(dobj));


    struct demo1 dobj1;
    printf("size of struct demo -> %ld\n",sizeof(dobj1));

    return 0;
}