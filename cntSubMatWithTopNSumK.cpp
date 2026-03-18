#include<bits/stdc++.h>
using namespace std;
#define ll long long

int countSubmatrices(vector<vector<int>>& grid, int k)
{
    //Return the number of submatrices that contain the top left element of the grid and have sum less than or equal to k

    int m = grid.size(),n = grid[0].size();

    vector<vector<ll>>pref(m,vector<ll>(n,0));
    int cnt = 0;

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            pref[i][j] = grid[i][j];

            if(i>0)pref[i][j] += pref[i-1][j];
            if(j>0) pref[i][j] += pref[i][j-1];
            if(i > 0 && j > 0)pref[i][j] -= pref[i-1][j-1];

            if(pref[i][j] <= k)cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{7,6,3},{6,6,1}};
    cout<<countSubmatrices(g,18)<<endl;

    return 0;
}