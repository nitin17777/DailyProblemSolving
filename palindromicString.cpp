#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool palin(int n, int k, string s)
{
    int n = s.length();
    
    //Good pair: i, n-i+1 : si = sn-i+1 holds true

    

    
}

int main()
{
    int n = 6,k=2;
    string s = "000000";

    if(palin(n,k,s))
    {
        cout<<"Yes"<<endl;

    }
    else
    {
        cout<<"No"<<endl;

    }
    return 0;
    
}