#include <bits/stdc++.h>
using namespace std;

bool predictTheWinner(vector<int> &nums)
{
    int n = nums.size();

    /*
    Player 1 will start first

    In each turn, player can take element from either end

    And chosen element is added to their score

    Game ends when no element is remaining

    We have to justify if player 1 can win the game



    We have to make dp
    */

    // dp[l][r] = max score diff current player can achieve
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base Case: When single element is only there
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = nums[i];
    }

    for (int len = 2; len <= n; len++)
    {
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;

            int pl = nums[l] - dp[l + 1][r];
            int rl = nums[r] - dp[l][r - 1];

            dp[l][r] = max(pl, rl);
        }
    }
    // Player 1 wins if score difference >= 0
    return dp[0][n - 1] >= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {1, 5, 2};
    cout << (predictTheWinner(nums) ? "True" : "False") << endl;

    return 0;
}