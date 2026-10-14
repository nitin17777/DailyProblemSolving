#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;
    
        /*subarray balanced if : 

        sum of elements subarray from l to r is divisible by k
        length of this subarray >=k  : r-l+1 > k

        */

        //Determine total number of k balanced subarrays in array a

        vector<int>pref(n+1,0);

        for(int i = 1;i<=n;i++)
        {
            ll x;
            cin>>x;

            pref[i] = (pref[i-1]+x) % k;
        }

        vector<ll>cnt(k,0);
        ll ans=0;

        for(int i=k+1;i<=n;i++)
        {
            cnt[pref[i-k-1]]++;
            ans+=cnt[pref[i]];
        }
        cout<<ans<<'\n';
    }
    return 0;
}