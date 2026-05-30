#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> solve(vector<ll>& a, int n)
{
    vector<ll> ans;

    ll pref = 0;
    ll mn = LLONG_MAX;

    for(int i = 0; i < n; i++)
    {
        pref += a[i];

        mn = min(mn, pref / (i + 1));

        ans.push_back(mn);
    }

    return ans;
}

      
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
        for(auto &x:a)cin>>x;

        vector<ll>ans = solve(a,n);

        for(auto& x:ans)cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}