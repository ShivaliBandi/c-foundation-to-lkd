#include<iostream>
#include <string>

using namespace std;
class Employee
{
    private:
        string name;
        int salary;
    public:
        void setDetails(string name,int salary)
        {
            this->name=name;
           this->salary=salary;
            
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
        void compareSalary(Employee &other)
        {
            if (this->salary > other.salary)
                cout << "Salary of first object is greater than second object\n";
            else if (this->salary < other.salary)
                cout << "Salary of first object is less than second object\n";
            else
                cout << "Both salaries are equal\n";
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
    cout<<"////////////////////////////////////////////////////////////////"<<endl;
    eobj1.compareSalary(eobj2);
    return 0;
}