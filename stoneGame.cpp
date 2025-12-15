#include <bits/stdc++.h>
using namespace std;

bool stoneGame(vector<int> &piles)
{

    /*
    since there are even number of piles, alice will always win no matter what,as they are playing optimally
    */

    /*
    Objective of game is to end the with most stones, no tie is possible

    Alice starts the game

    In each turn player takes pile of stone from either starting or end of the row

    When no more pile of stone is remaing, the person with greater number of stones wins

    True-> Alice, False->Bob
    */

    int n = piles.size();

    int a = 0, b = 0;

    int i = 0, j = n - 1;

    while (i <= j)
    {
        a += max(piles[i], piles[j]);

        b += min(piles[i], piles[j]);

        i++;
        j--;
    }

    return a > b;
}

bool stoneGame(vector<int> &piles)
{
    int n = piles.size();

    // dp[i][i] -> max score difference
    vector<vector<int>> dp(n, vector<int>(n));

    // Base case
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = piles[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> p = {5, 3, 4, 5};
    cout << (stoneGame(p) ? "True" : "False") << endl;

    return 0;
}