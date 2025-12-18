#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long maximumProfit(vector<int> &prices, int k)
{

    int n = prices.size();
    const long long NEG_INF = -1e18;

    /*
    dp[t][0] → free
    dp[t][1] → holding long
    dp[t][2] → holding short
    */
    vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG_INF));

    // Day 0 initialization
    dp[0][0] = 0;
    dp[0][1] = -prices[0]; // buy
    dp[0][2] = prices[0];  // short sell

    for (int i = 1; i < n; i++)
    {
        vector<vector<long long>> newdp = dp;

        for (int t = 0; t <= k; t++)
        {

            // ===== FREE =====
            newdp[t][0] = dp[t][0];

            if (t > 0)
            {
                newdp[t][0] = max(newdp[t][0], dp[t - 1][1] + prices[i]);
                newdp[t][0] = max(newdp[t][0], dp[t - 1][2] - prices[i]);
            }

            // ===== LONG =====
            newdp[t][1] = max(dp[t][1], dp[t][0] - prices[i]);

            // ===== SHORT =====
            newdp[t][2] = max(dp[t][2], dp[t][0] + prices[i]);
        }

        dp = newdp;
    }

    long long ans = 0;
    for (int t = 0; t <= k; t++)
        ans = max(ans, dp[t][0]);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> prices = {1, 7, 9, 8, 2};
    cout << maximumProfit(prices, 2) << endl;

    return 0;
}