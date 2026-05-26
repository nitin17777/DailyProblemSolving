#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll k)
{
    /*

    For each bulb i = 1,2,3...n , flip the state of all bulbs j such that j is divisible by i

    After performing all ops -> We have to make number of bulbs on  = k
    

    ///find the smallest possible n such that after performing operations , exactly k bulbs are on 


    Non perfect square -> ON
    Perfect Square -> Off
    */

    ll l = 1,r = 2e18;

    while(r-l >1)
    {
        ll mid = (l+r)>>1;

        ll cnt = mid-int(sqrtl(mid));

        if(cnt >= k)
        {
            r=mid;
        }
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
        ll n;
        cin>>n;

        cout<<solve(n)<<endl;
    }

    return 0;
}