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

        vector<int>c(2*n);
        for(auto&x:c)cin>>x;
        
        unordered_map<int,int>freq;

        for(auto&x:c)freq[x]++;

        int ans = 0;
        for(auto&x:freq)ans=max(ans,x.second);
        cout<<ans<<'\n';
    }
    return 0;
}