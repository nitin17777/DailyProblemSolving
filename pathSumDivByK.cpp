#include <bits/stdc++.h>
using namespace std;

// did it with ai help mostly
int numberOfPaths(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();

    const int MOD = 1e9 + 7;

    // dp[i][j][r] = number of ways to reach i,j with oath sum mod k
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

    dp[0][0][grid[0][0] % k] = 1; /// starting cell

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue; // skipping the starting cell

            /*
            dp[i-1][j][oldr] => Coming from top
            dp[i][j-1][oldr]=>coming rom left

            */

            for (int oldr = 0; oldr < k; oldr++)
            {
                int cell = grid[i][j];

                // if previous path had rem oldr, then newRem after adding current cell is : newr = (oldr + cell value )%k

                int newr = (oldr + cell) % k;

                if (i > 0)
                {
                    dp[i][j][newr] = (dp[i][j][newr] + dp[i - 1][j][oldr]) % MOD;
                }

                if (j > 0)
                {
                    dp[i][j][newr] = (dp[i][j][newr] + dp[i][j - 1][oldr]) % MOD;
                }
            }
        }
    }
    return dp[n - 1][m - 1][0];
}

/*

int cnt = 0;

void dfs(vector<vector<int>>&a,int i ,int j,int curr,int n,int m,int k)
{
    curr+=a[i][j];

    if(i == n-1 && j == m-1)
    {
        if(curr % k == 0)cnt++;
        return;
    }

    //Move Down
    if(i+1<n)dfs(a,i+1,j,curr,n,m,k);

    //Move Right
    if(j+1<m)dfs(a,i,j+1,curr,n,m,k);
}

int numberOfPaths(vector<vector<int>>& grid, int k)
{
    //We can only right and down
    //Return the number of paths whose sum is divisible by k

    //iterate over all paths => find sum and check divisibility
    int n = grid.size();
    int m = grid[0].size();

    dfs(grid,0,0,0,n,m,k);

    return cnt;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};

    cout << numberOfPaths(grid, 3) << endl;

    return 0;
}
