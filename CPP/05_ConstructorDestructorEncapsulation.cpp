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
        ~Employee()
        {
            cout<<"inside Destructor"<<endl;
        }
       
};

int main()
{

   Employee e1(50000);

    e1.increaseSalary(5000);

    cout << e1.getSalary() << endl;
    return 0;
}