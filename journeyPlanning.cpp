#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];

    /*

    n cities are situated along main railroad line of Berland

    city c1 to start with, and then go to some city c2 with c2 > c1 and then so on similarly until she chooses to end her jounrey in some city

    so ultimately the sequence of visited cities should be strictly increasing 
    
    Determine the max beauty value of the journey


    */

    map<ll,ll>sum;

    for(int i =1;i<=n;i++)
    {
        sum[i-a[i]]+=(a[i]);
    }

    ll ans=0;
    for(auto&it:sum)
    {
       ans = max(ans,it.second);  
    }

    cout<<ans<<'\n';

    return 0;
}