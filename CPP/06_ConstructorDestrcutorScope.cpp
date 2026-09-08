#include<iostream>
using namespace std;
class Test
{
    public:
        Test()
        {
            cout<<"constructor\n";
        }
        ~Test()
        {
            cout<<"Destructor\n";
        }
};
int main()
{
    Test a;
    {
        Test b;
        cout<<"Inside\n";
    }
    cout<<"Ouside\n";
    return 0;
}
/*
expected sequence is 
Constructor
Constructor
inside
destructor
outside
destructor
*/