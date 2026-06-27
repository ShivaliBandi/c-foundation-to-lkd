#include<stdio.h>
#include<stdarg.h>
int iMaximum(int icount,...)
{
    
    va_list list;
    va_start(list,icount);
    int iMax=va_arg(list,int);
    for(int i=1;i<icount;i++)
    {
        int value = va_arg(list, int);
        if(iMax< value)
            iMax=value;
    }
    va_end(list);
    return iMax;
}
int main()
{
    printf("iMax=%d\n",iMaximum(5,100,23,5432,2,332));
    return 0;
}