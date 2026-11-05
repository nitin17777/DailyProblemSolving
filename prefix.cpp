#include<bits/stdc++.h>
#define ll long long
using namespace std;


int pref(vector<int>&a,int k)
{
    int ans = 0;

    for(int i =1;i<k;i++)ans+=a[i];
    
    return ans;
}


//Didn't fully understood this      
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

        //s = prefix[i]

        // find: max(a)after doing this process

        ll L = 0,H=0;
        ll ans = LLONG_MIN;

        for(int i =0;i<n;i++)
        {
            ans = max(ans,max(a[i] + H, a[i]-L));

            ll newL = min(a[i],a[i]+2*L);
            ll newH = max(a[i],a[i]+2*H);

            L = newL,H = newH;
        }
        cout<<ans<<'\n';
    }
    return 0;
}