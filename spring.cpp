#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll getOne(ll a, ll m)
{
    return m/a;
}

ll getTwo(ll a, ll b, ll m)
{
    return m / lcm(a,b);
}

ll getThree(ll a, ll b,ll c,ll m)
{
    return m / lcm(lcm(a,b),c);
}


ll get(ll a,ll b, ll c,ll m)
{
    ll c1 = getOne(a,m);
    ll c2 = getTwo(a,b,m) + getTwo(a,c,m);
    ll c3 = getThree(a,b,c,m);

    return(c1-c2+c3)* 6 + (c2- 2* c3)*3 + c3*2;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll a,b,c,m;
        cin>>a>>b>>c>>m;

        /*

        One person -> 6l 
        2 people -> 3l
        3 people ->2l each

        Determine if how much warer they collect m days starting from day 1
        */

        cout<<get(a,b,c,m)<<" "<<get(b,a,c,m)<<" "<<get(c,a,b,m)<<endl;    
    }

    return 0;
}