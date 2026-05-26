#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<int>dx = {1,-1,0,0};
vector<int>dy = {0,0,1,-1};

int dfs(vector<vector<int>>&mat,vector<vector<int>>&dp,int i,int j)
{

    if(dp[i][j] != -1)return dp[i][j];

    int m = mat.size(),n = mat[0].size();

    int ans = 1;

    for(int k = 0;k<4;k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni >= 0 && nj >= 0 && ni<m && nj <n && mat[ni][nj] > mat[i][j])
        {
            ans = max(ans,1 + dfs(mat,dp,ni,nj));
        }
    }
    return dp[i][j] = ans;
}


int longestIncreasingPath(vector<vector<int>>& mat)
{
    int m = mat.size(),n= mat[0].size();

    //Return the length of longest increasing path in the matrix

    vector<vector<int>>dp(m,vector<int>(n,-1));

    int res = 1;
    
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            res = max(res,dfs(mat,dp,i,j));
        }
    }
    return res;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>mat = {{9,9,4},{6,6,8},{2,1,1}};
    cout<<longestIncreasingPath(mat)<<endl;

    return 0;
}