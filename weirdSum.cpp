#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dist(vector<int>&a)
{
    sort(a.begin(),a.end());

    ll ans = 0;
    ll prefix = 0;

    for(int i=0;i<a.size();i++)
    {
        ans+=1LL *a[i]*i-prefix;
        prefix+=a[i];
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    map<int,vector<int>>rows,cols;

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int color;
            cin>>color;

            rows[color].push_back(i);
            cols[color].push_back(j);
        }
    }

    ll ans = 0;
    for(auto&[color,v]:rows)ans+=dist(v);
    for(auto&[color,v]:cols)ans+=dist(v);

    cout<<ans<<endl;

    return 0;
}