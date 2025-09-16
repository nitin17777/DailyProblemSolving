#include<iostream>
using namespace std;

string roman(int num)
{
    unordered_map<char,int>roman = 
    {
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };

    

}

int main()
{
    int num = 58;

    string ans = roman(num);

    cout<<ans<<endl;

    return 0;
}