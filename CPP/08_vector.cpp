#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}
int main()
{
    vector<int> ivector={5,3,8,3,1};
    print(ivector);
    cout<<"\n number of elements in vectors are->"<<ivector.size()<<endl;
    cout<<"first element in vector ->"<<ivector.front()<<endl;
    cout<<"last element in vector ->"<<ivector.back()<<endl;
    cout<<"Double every element using a reference loop, then print the result.\n";
    for(auto &i : ivector)
        i*=2;
    print(ivector);
    cout<<"Append 10, remove the first element, and insert 99 at index 2. Print after each step.\n";

    ivector.push_back(10);
    print(ivector);
    ivector.erase(ivector.begin());
    print(ivector);
    ivector.insert(ivector.begin()+2,99);
    print(ivector);
    int imax=ivector[0],index=0;
    for(int i=1;i<ivector.size();i++)
    {
        if(imax<ivector[i])
        {
            imax=ivector[i];
            index=i;
        }
    }
    cout<<"max element of vecotr is "<<imax<<"  at index "<<index<<endl;
    cout<<"Build a 3x3 2D vector where g[i][j] = i * j, and print it as a grid.\n";
    vector<vector <int>> matrix(3,vector<int>(3,0));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            matrix[i][j]=i*j;
    }
    for(const auto &row: matrix)
    {
        for(const auto &col: row)
            cout<<col<<" ";
        cout<<endl;
    }
        
    //first check if vector is empty 
    if(ivector.empty())
        cout<<"vector is empth can reverse the vector\n";
    else
    {
        for(int i:ivector)
            cout<<i<<" ";
        cout<<endl;
        for(int istart=0,iend=ivector.size()-1;istart<iend;istart++,iend--)
            std::swap(ivector[istart],ivector[iend]);
        print(ivector);

    }

    return 0;
}

/*

shivali-bandi@programmerInsane:~/Documents/c-foundation-to-lkd/CPP$ ./a.out
5 3 8 3 1 
 number of elements in vectors are->5
first element in vector ->5
last element in vector ->1
Double every element using a reference loop, then print the result.
10
6
16
6
2
Append 10, remove the first element, and insert 99 at index 2. Print after each step.
10      6       16      6       2       10
6       16      6       2       10
6       16      99      6       2       10
max element of vecotr is 99  at index 2
Build a 3x3 2D vector where g[i][j] = i * j, and print it as a grid.
0 0 0 
0 1 2 
0 2 4 
6 16 99 6 2 10 
10 2 6 99 16 6 
*/