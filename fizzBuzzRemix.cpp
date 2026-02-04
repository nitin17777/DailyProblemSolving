#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n)
{
    // For every number from 0 to n cnt for how many numbers n%3 == n%5

    ll ans = 3 * (n / 15);

    n %= 15;

    for (int i = 0; i <= n; i++)
    {
        if (i % 3 == i % 5)
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        cout << solve(n) << endl;
    }
    return 0;
}