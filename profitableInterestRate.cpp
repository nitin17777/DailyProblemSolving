#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b)
{

    /*

    Min cost to open a profitable deposit is b coins

    And if we open an unprofitable deposit with x coins , min amount to open a profitable one will be 2x coins, but these coins cannot be deposited into profitable one


    Return the max number of coins she can deposit into profitable deposit if she first deposits some coins in unprofitable one already
    */

    if (a > b)
        return a;

    int x = b - a;
    if (a - x < 0)
        return 0;
    else
        return a - x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        cout << solve(n, m) << endl;
    }
    return 0;
}