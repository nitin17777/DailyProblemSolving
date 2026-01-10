#include <bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2)
{
    // We have to retrun the lowest ASCII sum of deleted characters to make two strings equal

    /* ALGO: Find the total ascii sum firstly -> Then find the commmon substring and find it's ascii value.
    Then : ans = total ascii - 2* common's ascii

    */

    int n = s1.size(), m = s2.size();
    int result = 0;

    int ss1 = 0;
    for (auto x : s1)
        ss1 += x;

    int ss2 = 0;
    for (auto x : s2)
        ss2 += x;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                // Take if the characters match
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            }

            // otherwise we can skip one character and take the better one
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int commonASCSum = dp[n][m];

    return ss1 + ss2 - 2 * (commonASCSum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "sea", s2 = "eat";
    cout << minimumDeleteSum(s1, s2) << endl;

    return 0;
}