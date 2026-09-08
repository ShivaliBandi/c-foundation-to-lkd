#include<iostream>
using namespace std;
class Employee{
    private:
        int salary;
    public:
        Employee(int salary)
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
        ~Employee()
        {
            cout<<"inside Destructor"<<endl;
        }
       
};
void giveRaise(Employee &e, int amount)
        {
            e.increaseSalary(amount);
        }
int main()
{

    Employee e1(50000);

    Employee &ref = e1;

    giveRaise(ref, 10000);

    cout << e1.getSalary() << endl;
    return 0;
}