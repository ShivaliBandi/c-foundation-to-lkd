#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;

void print(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}
int main()
{
    string s1="shivali";
    unsigned int icountVowels=0;
    for(char i: s1)
    {
        if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u')
            icountVowels++;
    }
    cout<<"Vowel count "<<icountVowels<<endl;\

    string s2="abcddcba";
    std::string s3=s2;
    
    cout<<s3<<endl;
    for(int istart=0,iend=s2.size()-1;istart<iend;istart++,iend--)
    {
        std::swap(s2[istart],s2[iend]);
    }
    if(s2==s3)
        cout<<"String is palindrome\n";
    else
        cout<<"String is not palindrome\n";

    vector<int> v={5,2,9,1};
    print(v);
    sort(v.begin(),v.end(),greater<int>());
    print(v);




    /////////////////////////////////////////////////////////////////////////////////////////////////
    vector<pair<string,int>> svector={{"amy",90}, {"raj",85}, {"bob",90}};

    for(auto [iname,marks]:svector)
        cout<<iname<<":"<<marks<<endl;
    sort(svector.begin(), svector.end(), [](const pair<string,int>& x, const pair<string,int>& y) {
    return x.first < y.first; });     // by second, descending

    for(auto [iname,marks]:svector)
        cout<<iname<<":"<<marks<<endl;
   
}
