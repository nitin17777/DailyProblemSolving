#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> constructProductMatrix(vector<vector<int>>& g)
{
    int n= g.size(),m = g[0].size();

    int MOD = 12345;
    int N = n*m;
    vector<ll>arr,pref(N,1),suff(N,1);

    //Flattening the matrix first
    for(auto & row : g)
    {
        for(auto & x:row)arr.push_back(x);
    }

    //Prefix product
    for(int i = 1;i<N;i++)
    {
        pref[i] = (pref[i-1]*arr[i-1])%MOD;
    }

    //Suffix product now
    for(int i = N-2;i>=0;i--)
    {
        suff[i] = (suff[i+1]*arr[i+1])%MOD;
    }

    //Building gthe final arr now 
    vector<vector<int>>ans(n,vector<int>(m));
    for(int i = 0;i<N;i++)
    {
        ll val = (pref[i] * suff[i]) %MOD;
        ans[i/m][i%m] = val;//
    }
    return ans;
}

/*          NOT APPLICABLE FOR LARGE INPUTS


vector<vector<int>> constructProductMatrix(vector<vector<int>>& g)
{
    int n= g.size(),m = g[0].size();

    ll multi = 1;


    for(auto & an:g)
    {
        for(auto &a:an)
        {
            multi*=a;
        }
    }


    vector<vector<int>>p(n,vector<int>(m,multi));

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            p[i][j] = (p[i][j]/g[i][j])%12345;
        }
    }
    return p;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{1,2},{3,4}};
    vector<vector<int>>ans = constructProductMatrix(g);

    for(auto& an:ans)
    {
        for(auto &a:an)cout<<a<<" ";

        cout<<endl;
    }
    
    return 0;
}