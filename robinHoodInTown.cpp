#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll minGold(vector<ll> &wealth)
{
    int n = wealth.size();

    // Special case: if n <= 2, more than half can never be unhappy
    if (n <= 2)
        return -1;

    sort(wealth.begin(), wealth.end()); // to find average money etc

    // so basically kth person (i.e more than half population = n/2 +1 persons) should have less than average money

    /* a[k] < avg /2;
        a[n/2 + 1] < sum +x / 2n => x > a[k] *2n - s

        => so x = a[k]*2n -s +1 -------->Ans


    */

    // n , ak , s

    int k = n / 2 + 1;
    ll ak = wealth[k - 1];

    ll s = accumulate(wealth.begin(), wealth.end(), 0LL);

    ll ans = max(0LL, 2 * n * ak - s + 1);
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> wealth(n);
        for (auto &x : wealth)
            cin >> x;

        cout << minGold(wealth) << endl;
    }
    return 0;
}