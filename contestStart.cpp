#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n ,ll x,ll t)
{
    /*They participate in time intervals of x mins: 0 , x, 2x....

    Duration of contest is t mins for each participant
    
    */

    ll k = t/x; //Max overall per participant

    //Participants gettign full k dissatisfaction
    ll full = max(0LL, n-k) * k;

    ll m = min(n-1,k-1);
    ll tail = m * (m+1)/2;

    return full + tail;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,t;
        cin>>n>>x>>t;
        
        cout<<solve(n,x,t)<<endl;
    }
    return 0;
}