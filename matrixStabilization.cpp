#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>>solve(vector<vector<ll>>&a)
{
    int n = a.size(),m=a[0].size();

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    //Return the matrix after stabilisation is done


    vector<vector<ll>> res = a;

    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            ll maxi = LLONG_MIN;

            for(int d = 0;d<4;d++)
            {
                int ni = i + dx[d];
                int nj = j + dy[d];
                
                if(ni >= 0 && ni < n && nj >=0 && nj<m)
                {
                    maxi = max(maxi, a[ni][nj]);  
                }         
            }

            if(a[i][j] > maxi)
            {
                res[i][j] = maxi;
            }
        }
    }
    return res;
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >>n>>m;

        vector<vector<ll>>a(n,vector<ll>(m));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        vector<vector<ll>>ans = solve(a);

        for(auto & an:ans)
        {
            for(auto&a :an)cout<<a<<" ";

            cout<<endl;
        }
    }
    return 0;
}