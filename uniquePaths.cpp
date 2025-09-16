#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n)
{
    //We have to find how many unique paths are possible to reach the bottom right corner
    vector<vector<int>>dp(m,vector<int>(n,1));//Made a 2d array according to given table

    
    for(int i = 1 ;i < m; i++)
    {
        for(int j =1;j<n;j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int m = 3, n = 7;

    int ans = uniquePaths(m,n);

    cout<<ans<<endl;

    return 0;

}