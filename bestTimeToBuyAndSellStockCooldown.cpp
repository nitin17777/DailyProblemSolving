#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // Return the max profit we can have

    // After we sell a stock, we can not buy stock the next day

    int hold = -prices[0]; // bought on day 0
    int sold = 0;          // Can't sell on day 0
    int rest = 0;          // Do nothing

    for (int i = 1; i < prices.size(); i++)
    {
        int prevHold = hold;
        int prevSold = sold;
        int prevRest = rest;

        // Hold the stock or buy today from rest
        hold = max(prevHold, prevRest - prices[i]);

        // Sell today (for this, we must have stock yesterday)
        sold = (prevHold + prices[i]);

        /// Rest or cooldown after selling
        rest = max(prevRest, prevSold);
    }

    return max(sold, rest);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}