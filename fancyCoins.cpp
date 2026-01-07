#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll m, ll k, ll a1, ll ak)
{
    /*
    He has two types of coins:
    coins worth 1 burle: Regular coins and many fancy coins
    coins worth k burles: Regular coins and many fancy coins


    Wants to make a purchase such that no change is there
    total worth of coins is m exactly

    He want to use least possible fancy coins as possible

    Return the smallest number of fancy coins he can use to make a purchase

    m = cost of purchase
    k = worth of second type of coin
    and amount of coins worth 1 and k respectively

    */

    // 1-> Taking as many as k coins as possible
    ll totalK = m / k;
    ll total1 = m % k;

    // 2 -> Now among k coins, use regular ones first
    ll regularK = min(ak, totalK);
    ll fancyK = totalK - regularK;

    // 3 ->Use regular ones first among 1-coins
    ll regular1 = min(a1, total1);
    ll fancy1 = total1 - regular1;

    // Count unused regular 1 coins
    ll unusedReg1 = a1 - regular1;

    // Replacing fancy k coins with regular 1 coins if possible
    // And each replacement will reduce fancy count by 1
    ll replacements = min(fancyK, unusedReg1 / k);

    fancyK -= replacements;

    return fancyK + fancy1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll m, k, a, b;
        cin >> m >> k >> a >> b;

        cout << solve(m, k, a, b) << endl;
    }
    return 0;
}