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
        cin>>n;

        vector<ll>a(n);
        for(auto&x:a)cin>>x;

        //find Max value of array after performing all these ops
        ll ans = a[0];
        ll sum = a[0];

        for(int i = 1;i<n;i++)
        {
            a[i] = max(a[i]+sum,a[i]-sum);

            ans = max(ans,a[i]);

            sum+=a[i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}