#include <iostream>
#include <vector>
using namespace std;

// Didn't did it myself but learnt the approach
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    const int infinity = 1e9;

    vector<int> dp(amount + 1, infinity);

    dp[0] = 0; // since we need 0 coins to make 0 amount

    // Building dp array from 1 to amount
    for (int x = 1; x <= amount; x++)
    {
        // Try using every coin one by one
        for (int coin : coins)
        {
            // If this coin can be used
            if (coin <= x)
            {
                dp[x] = min(dp[x], dp[x - coin] + 1);
            }
        }
    }
    return (dp[amount] == infinity) ? -1 : dp[amount];
}

/* This approach is fine for canonical coins only,therfore we will be going with dp method to solve this question

int coinChange(vector<int>& coins, int amount)
{
    //return min number of coins to complete the given amount

    int n = coins.size();
    sort(coins.begin(),coins.end());
    int count = 0;

    for(int i = n-1;i>=0;i--)
    {
        int take = amount / coins[i];
        count+=take;

        amount = amount - (take * coins[i]);
    }

    if(amount != 0)return -1;
    return count;
}*/

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 11) << endl;

    return 0;
}
