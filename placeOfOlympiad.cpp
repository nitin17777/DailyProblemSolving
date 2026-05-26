#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n,ll m,ll k)
{
    /*

    n*m grid,
    Each of rhe k participant will sit in individual bench

    //Consecutive desks =  bench

    find the minimum possible length of longest bench


    */

    ll l=0,r=m;

    while(l+1 < r)
    {
        ll mid = (l+r)/2;

        if((m / (mid +1) * mid + m%(mid +1)) *n >=k)r = mid;
        else l = mid;
    }
    return r;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;

        cout<<solve(n,m,k)<<endl;    
    }

    return 0;
}