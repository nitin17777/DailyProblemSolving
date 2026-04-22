#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(ll x,ll y)
{
    /*

    y is divisble by x

    Determine if  x < z < y
                  z is divible by x
                  y is not divisible by z


    */
    //not possible if x and y are consecutive
    ll k = y/x;
    return (k>2);

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        cout<<(solve(n,m)?"YES":"NO")<<endl;
    
    }

    return 0;
}