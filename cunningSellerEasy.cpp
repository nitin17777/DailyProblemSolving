#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll seller(ll n)
{
    // he can sell 3^x watermelons for 3 ^ x+1 +  x⋅3^x−1 = 3^(x-1) * (9+x)

    // buy exactly n watermelons such that he has to make least possible number of deals
    // 1 watermelons for 3
    // 3 watermelons for 9 + 1 = 10 coins  --> 1 for 3.33
    // 9 watermelons for 27 + 6 = 33 coins -->1 for 3.66
    // 27 watermelons for 108 coins -->1 for 3.27

    // precomputing prices for all deals
    vector<ll> cost;

    ll c = 3; // since initial cost[0] = 3

    ll cnt = 1;

    for (int i = 0; i < 21; i++) // 21 since 3^21 > 1e9
    {
        cost.push_back(c);

        c = 3 * c + cnt;
        cnt *= 3;
    }

    ll minCost = 0;
    int sz = 0; // To track at which ternary digit we are at

    while (n > 0)
    {
        int digit = n % 3; // kth ternary digit
        minCost += digit * cost[sz];

        // Moving to next ternary digit now
        n /= 3;
        sz++;
    }
    return minCost;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        cout << seller(n) << endl;
    }
    return 0;
}
