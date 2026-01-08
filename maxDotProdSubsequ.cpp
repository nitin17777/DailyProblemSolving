#include <bits/stdc++.h>
using namespace std;
const int NEG = -1e9;

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    // Find the dot product bw subseq of nums1 and nums2 having same length

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int prod = nums1[i - 1] * nums2[j - 1];

            dp[i][j] = max({dp[i - 1][j],                      // leave from nums1
                            dp[i][j - 1],                      // leave from nums2
                            prod + max(dp[i - 1][j - 1], 0)}); // use both
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> n1 = {2, 1, -2, 5};
    vector<int> n2 = {3, 0, -6};

    cout << maxDotProduct(n1, n2) << endl;

    return 0;
}