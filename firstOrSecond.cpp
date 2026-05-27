#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll>&a,ll n)
{

    /*

    X = 0 initially
    n-1 operations would be there in total


    1st -> Add w to X
    2nd ->Subtract w from X

    //Determine the max possible X after n-1 operations


    2nd child would be only taken if it is negative 

    else 1st child always

    else if 1st positive and 2nd negative -> Compare their absolute values
    

    */

    vector<ll>pref(n+1),suff(n);

    for(int i = 1;i<n;i++)pref[i+1] = pref[i] + abs(a[i]);
    for(int i = n-1;i>=1;i--)suff[i-1] = suff[i] - a[i];

    ll ans = suff[0];
    for(int i = 1;i<n;i++)
    {
        ans = max(ans,a[0]+pref[i]+suff[i]);
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
        ll n;
        cin>>n;

        vector<ll>a(n);
        for(auto&x:a)cin>>x;

        cout<<solve(a,n)<<endl;  
    }

    return 0;
}