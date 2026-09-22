#include<bits/stdc++.h>
#define ll long long
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& a)
{
    int m = a.size(),n = a[0].size();


    //Return total possible paths to reach the bottom right corner

    //Can move only right or down


    //dp[i][j] = no. of unique ways to reach (i,j)
    vector<vector<int>>dp(m,vector<int>(n,0));

    //dp[i][j] = dp[i-1][j] + dp[i][j-1]

    //And when encountered an obstacle,put that dp[i][j] = 0

    if(a[0][0] == 1)return 0;
    if(a.size()==1 && a[0].size()==1 && a[0][0] == 1)return 0;
    if(a.size()==1 && a[0].size()==1 && a[0][0] == 0)return 1;


    dp[0][0] = 1;

    //fill first row and column
    for(int i=1;i<n;i++)
    {
        if(a[0][i] == 0)
        {
            dp[0][i] += dp[0][i-1];
        }
        else dp[0][i] = 0;
    }

    for(int i=1;i<m;i++)
    {
        if(a[i][0] == 0)
        {
            dp[i][0] += dp[i-1][0];
        }
        else dp[i][0] = 0;
    }


    //Now filling rest of the matrix
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(i>=1 && j>=1)
            {
                if(a[i][j] != 1)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else dp[i][j] = 0;  
            }
        }
    }
    return dp[m-1][n-1];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>a = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePathsWithObstacles(a)<<endl;

    return 0;
}