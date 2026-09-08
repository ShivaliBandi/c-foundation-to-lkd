#include<iostream>
using namespace std;
class Employee{
    private:
        int salary;
    public:
        
        void setSalary(int salary)
        {
            this->salary=salary;
        }
        int getSalary()
        {
            return this->salary;
        }
        void increaseSalary(int amount)
        {
            salary+=amount;
        }
       
};
void giveRaise(Employee &e, int amount)
        {
            e.increaseSalary(amount);
        }
void compareSalary(Employee &e1, Employee &e2)
{
    (e1.getSalary() > e2.getSalary())? cout<<"object 1 salary is greater then object 2"<<endl :
     cout<<"object 2 salary is greater then object 1"<<endl; 
}
int main()
{

    // Employee eobj;
    // Employee &ref=eobj;
    // eobj.setSalary(50000);
    // eobj.getSalary();
    // ref.increaseSalary(5000);
    // eobj.getSalary();
    // giveRaise(eobj,10000);
    // eobj.getSalary();
    Employee eobj1,eobj2;
    eobj1.setSalary(50000);
    eobj2.setSalary(20000);
    compareSalary(eobj1,eobj2);
    return 0;
}