#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>solve(vector<ll>a,vector<ll>&b,int n,int m)
{
    /*

    ith step is ai meter higher than prefecessor
    For each ki print max height that can be achieved if legs are of length ki
    
    */

    vector<ll>ans;

    vector<ll>pref(n),mxm(n);
    mxm[0] = a[0];
    pref[0] = a[0];
    for(int i = 1;i<n;i++)
    {
        pref[i] = pref[i-1] + a[i];
        mxm[i] = max(mxm[i-1],a[i]);
    }

    for(int i=0;i<m;i++)
    {
        int k = b[i];

        //Largest index which has mxm greater than k
        int idx = upper_bound(mxm.begin(),mxm.end(),k) - mxm.begin() -1;

        if(idx <0)ans.push_back(0);

        else ans.push_back(pref[idx]);
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
        int n,q;
        cin>>n>>q;

        vector<ll>a(n),k(q);
        for(auto&x:a)cin>>x;
        for(auto&x:k)cin>>x;

        vector<ll>ans=solve(a,k,n,q);
        for(auto&x:ans)cout<<x<<" ";
        
        cout<<endl;



    
    }

    return 0;
}