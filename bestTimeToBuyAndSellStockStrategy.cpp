#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
{
    /*
    -1 =>buyinng 1 unit
    0 => holing the stock
    1 => selling 1 unit


    One modification in "strategy " includes :
                               set first k/2 elements to 0(hold)
                               set first k/2 elements to 1(sell)
                               But these k elments must be consecutive





    Profit = strategy[i]  * prices[i]


    Return the max profit that can be achieved
    */

    // for every window of length k,compute how much profit we can make if we apply modification there

    int n = prices.size();

    // calculating base profit firstly
    ll base = 0;
    for (int i = 0; i < n; i++)
    {
        base += 1LL * strategy[i] * prices[i];
    }

    // Building prefix Sums for both prices and  base costs
    vector<ll> P(n + 1, 0), S(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        P[i + 1] = P[i] + 1LL * prices[i] * strategy[i];
        S[i + 1] = S[i] + prices[i];
    }

    // Trying every window of length k

    // In each window, set first k/2 elements to 0
    // And last k/2 elements to 1

    ll bestDelta = 0;
    int half = k / 2;

    // boundares: (1 - mid-1) and  (mid - r-1)
    for (int l = 0; l + k <= n; l++)
    {
        int mid = l + half;
        int r = l + k;

        // A = original profit contributed by first half
        ll A = P[mid] - P[l];

        // B= original profit contributed by second half
        ll B = P[r] - P[mid];

        // c = total price of second half
        ll C = S[r] - S[mid];

        ll delta = -A + (C - B); // Gain from second half - loss from first half

        bestDelta = max(delta, bestDelta);
    }

    return base + bestDelta;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> prices = {4, 2, 8};
    vector<int> str = {-1, 0, 1};
    cout << maxProfit(prices, str, 2) << endl;

    return 0;
}