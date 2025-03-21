#include<iostream>
using namespace std;

string rempart(string s,string part)
{
    while(s.length()!=0 && s.find(part)<s.length())

    {
        s.erase(s.find(part),part.length());
    }
    return s;
    

}

int main()
{
    string gg = "gobcoogle";

    cout<<rempart(gg,"obc")<<endl;

    return 0;

}
