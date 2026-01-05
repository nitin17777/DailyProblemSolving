#include <bits/stdc++.h>
using namespace std;

int maxNum;
unordered_map<int, bool> memo;

bool dfs(int mask, int rem)
{
    // if already computed, return the stored result
    if (memo.count(mask))
        return memo[mask];

    // Try all possible unused numbers
    for (int i = 1; i <= maxNum; i++)
    {
        int bit = 1 << (i - 1);

        /// if number i is unused
        if ((mask & bit) == 0)
        {
            // if picking i wins immediately
            if (i >= rem)
                return memo[mask] = true;

            // Otherwise see if opponent loses
            if (!dfs(mask | bit, rem - i))
            {
                return memo[mask] = true;
            }
        }
    }
    return memo[mask] = false; // when no winning move exists
}

bool canIWin(int maxi, int desi)
{
    /*

    The player who first causes the running total to reach or exceed 100 wins


    Return true if first player to move can force a win
    */

    int s = (maxi * (maxi + 1)) / 2;
    if (desi <= 0)
        return true;

    if (s < desi)
        return false;

    maxNum = maxi;
    // Starting with empty mask
    return dfs(0, desi);
}

int main()
{
    cout << (canIWin(10, 11) ? "true" : "false") << endl;
    return 0;
}