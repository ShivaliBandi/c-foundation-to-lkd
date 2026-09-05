#include<iostream>
#include <string>

using namespace std;
class Employee
{
    private:
        string name;
        int salary;
    public:
        void setDetails( string Name,int Salary)
        {
            name=Name;
            salary=Salary;
            
        }
        void display()
        {
            cout<<"Name is "<<name<<"\n";
            cout<<"Salary is "<<salary<<"\n";
        }
        void increaseSalary(int amount)
        {
            salary+=amount;
        }
};

int main()
{
    Employee eobj1,eobj2;
    eobj1.setDetails("Shivali",17);
    eobj1.display();
    eobj1.increaseSalary(10);
    eobj1.display();

    eobj2.setDetails("Sweety",20);
    eobj2.display();
    eobj2.increaseSalary(7);
    eobj2.display();
    return 0;
}