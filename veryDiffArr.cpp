#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll solve(vector<int>&a,vector<int>&b)
{
    int n =a.size(),m = b.size();


    ///Find the max diff D he can obtain

    // 1 2 4 6
    // 7 5 3 3 2 1
    //

    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());

    vector<int>c(n);

     // Start with n smallest elements of b
    for(int i = 0; i < n; i++)c[i] = b[m - n + i];
    
    ll s = 0;

    ll ans = 0;

    for(int i = 0; i < n; i++)s += abs(a[i] - c[i]);

    ll ans = 0;


    for(int k = 0; k < n; k++)
    {
        // replace c[k] with k-th largest b
        s -= abs(a[k] - c[k]);
        c[k] = b[k];
        s += abs(a[k] - c[k]);

        ans = max(ans, s);
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
        int n,m;
        
        cin>>n>>m;

        vector<int>a(n),b(m);
        for(auto & x:a)cin>>x;
        for(auto & x:b)cin>>x;
        
        cout<<solve(a,b)<<endl;
    }
    return 0;
}