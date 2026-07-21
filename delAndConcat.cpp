#include<bits/stdc++.h>
#define int long long
using namespace std;

      
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,c;
        cin>>n>>c;

        vector<int>a(n+1);
        for(int i = 1;i<=n;i++)
        {
            cin>>a[i];
            a[i]-=c;
        }

        //Calculate the max possible final score we an achieve

        int ans=0;

        sort(a.begin(),a.end());

        for(int i = 0;i<n/2;i++)
        {
            a[i] = max(0LL,a[i]);
        }

        for (int x : a)ans += x;

        cout<<ans<<'\n';       
    }
    return 0;
}