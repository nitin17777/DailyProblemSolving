#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;

ll dist(vector<ll>&x,vector<ll>&y,int i,int j)
{
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k,s,t;
        cin>>n>>k>>s>>t;


        //we can either fly directly to our destination or go by visiting each city

        //First k cities are considered as major cities


        //Find min cost of all air tickets if he can take any number of flight

        vector<ll>x(n+1),y(n+1);
        for(int i =1;i<=n;i++)cin>>x[i]>>y[i];
    
        //First k cities are major cities


        //if no majore cities are there then min cost would be |xi-xj| + [yi-yj]

        //Going directly form A to C cannot be more costly than going like A->B->C

        //Fly directly
        ll ans = dist(x,y,s,t);

        ll fromA=INF;
        ll fromB=INF;

        for(int i=1;i<=k;i++)
        {
            fromA = min(fromA,dist(x,y,s,i));
            fromB = min(fromB,dist(x,y,t,i));

        }
        ans=min(ans,fromA+fromB);
        cout<<ans<<'\n';
    }
    return 0;
}


// 0 0
// 1 -2
// -2 1
// -1 3
// 2 -2
// -3 -3