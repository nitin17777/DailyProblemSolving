#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &piles)
{

    /*
    There are 3n piles of coins

    In each step, we will choose any 3 piles of coins

    Alice -> Pile with max coins
    You -> Pile with next max coins
    Bob will pick the last remaining pile

    piles[i] = number of coins in the ith pile

    Return the max number of coins that you can have

    */

    // 1 2 2 4 7 8

    // 1 2 3 4 5 6 7 8 9

    // 981 762 543

    int n = piles.size();
    sort(piles.begin(), piles.end());

    int ans = 0;
    int i = n - 2;

    for (int j = 0; j < n / 3; j++)
    {
        ans += piles[i];
        i -= 2;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> piles = {2, 4, 1, 2, 7, 8};
    cout << maxCoins(piles) << endl;
    return 0;
}