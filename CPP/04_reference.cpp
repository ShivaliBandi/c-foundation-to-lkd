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
        void getSalary()
        {
            cout<<this->salary<<endl;
        }
        void increaseSalary(int amount)
        {
            salary+=amount;
        }
};
int main()
{

    Employee eobj;
    Employee &ref=eobj;
    eobj.setSalary(50000);
    eobj.getSalary();
    ref.increaseSalary(5000);
    eobj.getSalary();
    return 0;
}