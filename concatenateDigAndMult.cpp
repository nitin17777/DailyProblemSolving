#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sumAndMultiply(int n)
{
    string s = to_string(n);

    ll sum = 0;
    for(auto & x:s)
    {
        if(x!='0')sum+=x-'0';
    }


    string num = "";
    for(auto& x:s)
    {
        if(x!='0')num+=x;
    }

    ll finNum = 0;
    for(auto& x:num)
    {
        finNum*=10;
        finNum +=(x-'0');
        
    }

    return finNum*sum;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<sumAndMultiply(10203004)<<'\n';
    return 0;
}