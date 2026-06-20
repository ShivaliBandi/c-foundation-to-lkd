#include"header.h"
#define SIZE 5
int main()
{

    struct student{
        int rollNumber;
        char name[10];
        float percentage;
    };
    struct student sobj[SIZE];
    struct student *sptr=sobj;
    for(int i=0;i<SIZE;i++)
    
        scanf("%d %s %f",&(sptr+i)->rollNumber,(sptr+i)->name,&(sptr+i)->percentage);
    
    for(int i=0;i<SIZE;i++)
    
        printf("\n\ndisplay roll number %d name %s  percentage %0.2f\n",(sptr+i)->rollNumber,(sptr+i)->name,(sptr+i)->percentage);
    
    return 0;
}