#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n)
{
    ll ans = 1LL;
    while(n>3)
    {
        n/=4;
        ans*=2;
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        cout<<solve(n)<<endl;
    
    }

    return 0;
}




