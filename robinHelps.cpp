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

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        int curr = 0;
        int ans = 0;

        for(int i =0 ;i<n;i++)
        {
            if(a[i] == 0 && curr>0)
            {
                curr--;
                ans++;   
            }
            if(a[i]>=k)curr+=a[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}