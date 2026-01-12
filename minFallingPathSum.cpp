#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix)
{
    // Return the min sum of all falling paths

    int n = matrix.size();

    // dp[i][j] will store the min falling path sum to reach i,j

    vector<vector<int>> dp = matrix;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int best = dp[i - 1][j];

            if (j > 0)
            {
                best = min(best, dp[i - 1][j - 1]); // check left diagonal
            }
            if (j + 1 < n)
            {
                best = min(best, dp[i - 1][j + 1]); // check right diagonal
            }

            dp[i][j] += best;
        }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> m = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    cout << minFallingPathSum(m) << endl;
    return 0;
}