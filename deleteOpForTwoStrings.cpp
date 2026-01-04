#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    // Return the number of steps to make w1 and w2 same
    // In one step we can delete exaactly one character in either string

    int n = word1.length(), m = word2.length();

    // dp[i][j] = length of longest common subsequence

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // if current characters match they must be part of the LCS
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            // IF they don't match we have 2 choices:
            //  Ignore the current char of word1
            //  ignore the current char of word2

            // SO take the better maximum
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lcs = dp[n][m];

    return (n - lcs) + (m - lcs); // Total lenngth - common part = Number of deletions done
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string w1 = "sea", w2 = "eat";

    cout << minDistance(w1, w2) << endl;
    return 0;
}