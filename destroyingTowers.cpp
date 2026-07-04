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

        vector<int>a(n);
        for(auto&x:a)cin>>x;


        int ans=a[0];
        for(int i=1;i<n;i++)
        {
            a[i] = min(a[i],a[i-1]);
            ans+=min(a[i],a[i-1]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}