#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    // each day we may decide to buy or sell the stock
    // we can hold at most oen share of the stock at any time

    // we can buy or sell the stock multiple times of the same day
    // return the max profit that can be achieved

    // Case : When the given array is in desecending order, return 0;

    // int n = prices.size();

    // vector<int>temp = prices;
    // sort(temp.begin(),temp.end());
    // if(temp == prices)return 0;

    // //Case : When the given array is in ascending order, return prices[n-1] - prices[0]
    // vector<int>tee = prices;
    // sort(tee.rbegin(),tee.rend());
    // if(tee == prices)return prices[n-1] - prices[0];

    // //edge cases are solved, now moving towards main logic
    int profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // ans = 7
    cout << maxProfit(prices) << endl;

    return 0;
}
