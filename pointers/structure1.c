#include"header.h"
int main()
{

    struct student{
        int rollNumber;
        char name[10];
        float percentage;
    };
    struct student sobj,sobj2;
    sobj.rollNumber=1;
    strcpy(sobj.name,"Shivali");
    sobj.percentage=99.99;
    printf("Student rollnumber: %d \t Sudent name: %s\t Student Percentage: %.2f\n",sobj.rollNumber,sobj.name,sobj.percentage);
    struct student *sptr=&sobj2;
    sptr->rollNumber=2;
    strcpy(sptr->name,"Mansi");
    sptr->percentage=100.00;
    printf("Student rollnumber: %d \t Sudent name: %s\t Student Percentage: %.2f\n",sptr->rollNumber,sptr->name,sptr->percentage);
    
    return 0;
}