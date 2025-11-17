#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    // find the max profit that can be acieved

    int hold = -prices[0]; // buying the first stock => max porfit if  holding any stock

    int notHold = 0; // no stock initially; =>  //buying the first stock =?max porfit if not holding any stock

    for (int i = 1; i < prices.size(); i++)
    {
        hold = max(hold, notHold - prices[i]);
        notHold = max(notHold, hold + prices[i] - fee);
    }
    return notHold;
}

int main()
{

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << maxProfit(prices, 2) << endl;

    return 0;
}
