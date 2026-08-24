#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll calcLessX(vector<ll>&a,ll x)
{
    int n=a.size();

    ll s = 0;
    for(auto&x:a)s+=x;


    int j = 0;
    ll ans = 0;

    for(int i = n-1;i>=0;i--)
    {
        while(j<n && s - a[i]-a[j] >= x)j++;


        //all n-j pairs nums would be valid
        ans+=n-j;
    }

    //To remove those pairs which we counted as (i,i) and satisfies S-2*a[i]<x 
    for(int i = 0;i<n;i++)
    {
        if(s-2*a[i] < x)ans--;
    }

    return ans/2;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;

        vector<ll>a(n);
        for(auto& x:a)cin>>x;

        //if we remove elements from i and j posis: sumof remaining elements have sum of atleast x and atmost y
    

        // int total = accumulate(a.begin(),a.end(),0);
        // if(x<=total && y>=total)
        // {
        //     cout<<0<<'\n';
        //     continue;
        // }
        // //Determine the number of such pairs 
        // sort(a.begin(),a.end());


        //If we remove nay pair new sum = sum-ai-aj

        //we will be calculatng: number of pairs with rem sum < y+1 - number of pairs with remaining sum <=x

        //S - ai-aj < x => ai + aj >= S-x

        sort(a.begin(),a.end());

        ll ans = calcLessX(a,y+1)-calcLessX(a,x);

        cout<<ans<<'\n';    
    }

    return 0;
}