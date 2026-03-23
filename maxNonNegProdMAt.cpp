#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

int maxProductPath(vector<vector<int>>& g)
{
    int m = g.size(),n = g[0].size();

    /*
    In each step, we can move right or down

    Find the max non-negative path from top right to left bottom 

    Traverse through all paths and find the product, return the max product path 
    if product is negative return -1
    */

    vector<vector<ll>>maxdp(m,vector<ll>(n));
    vector<vector<ll>>mindp(m,vector<ll>(n));
    
    maxdp[0][0] = mindp[0][0] = g[0][0];

    //Initiallising first col,  only one way to reach (i,0) is from (i-1, 0)
    for(int i = 1;i<m;i++)
    {
        ll val = maxdp[i-1][0] * g[i][0];

        //As only one path exists, so max and min are same
        maxdp[i][0] = mindp[i][0] = val;
    }

    //Initiallising first row now, only one way to reach (i,0) is from (i-1, 0)
    for(int j = 1;j<n;j++)
    {
        ll val = maxdp[0][j-1] * g[0][j];

        //As only one path exists, so max and min are same
        maxdp[0][j] = mindp[0][j] = val;
    }

    for(int i = 1;i<m;i++)
    {
        for(int j = 1;j<n;j++)
        {

            ll a = maxdp[i-1][j] * g[i][j];//From top max
            ll b = mindp[i-1][j] * g[i][j];// From top min
            ll c = maxdp[i][j-1] * g[i][j]; // From left max
            ll d = mindp[i][j-1] * g[i][j]; // Form left min

            maxdp[i][j] = max({a,b,c,d});
            mindp[i][j] = min({a,b,c,d});
            
        }
    }

    ll ans = (maxdp[m-1][n-1])%MOD;

    return ans < 0 ? -1 : ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{1,-2,1},{1,-2,1},{3,-4,1}};
    cout<<maxProductPath(g)<<endl;

    return 0;
}