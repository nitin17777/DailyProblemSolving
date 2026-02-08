#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll> &a, ll x, ll y)
{
    int n = a.size();
    /*

    In ith bank, he has ai rubles
    HE can transfer only x rubles at a time and y rubles will be credited only

    Determine the max number of rubles that can end up in a bank
    */
    vector<ll> k(n);
    ll total = 0;

    for (int i = 0; i < n; i++)
    {
        k[i] = a[i] / x;
        total += k[i];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ll money = a[i] + (total - k[i]) * y;
        ans = max(ans, money);
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
        ll n, x, y;
        cin >> n >> x >> y;

        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a, x, y) << endl;
    }
    return 0;
}