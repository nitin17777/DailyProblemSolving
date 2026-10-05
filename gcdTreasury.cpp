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
        int n;
        ll x;
        cin>>n>>x;

        vector<ll> a(n);

        for(auto &v:a)
        {
            cin>>v;
        }

        if(x==1)
        {
            cout<<0<<'\n';
            continue;
        }

        ll ans = 0;

        // Check every distinct prime factor of x
        for(ll p=2; p*p<=x; p++)
        {
            if(x%p!=0)
                continue;

            ll sum = 0;

            // Take all piles divisible by p
            for(auto v:a)
            {
                if(v%p==0)sum += v;
            }

            ans = max(ans,sum);

            // Remove this prime factor completely
            while(x%p==0)
                x/=p;
        }

        // Remaining x is a prime factor
        if(x>1)
        {
            ll sum = 0;

            for(auto v:a)
            {
                if(v%x==0)
                    sum += v;
            }

            ans = max(ans,sum);
        }

        cout<<ans<<'\n';
    }

    return 0;
}