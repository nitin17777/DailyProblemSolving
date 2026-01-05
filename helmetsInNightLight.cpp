#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll p, vector<ll> &a, vector<ll> &b)
{
    /*
    An important anouncement need to be notified by all n residents of village

    Shares the anouncement directly to one or more residents with cost of p for each person


    For each i if ith resident has got the announcement atleast once , he can share it to at most ai other residents with cost of bi per share

    Min cost to inform n residents about the annnouncement
    */

    int n = a.size();

    // We share the initial announcement with residents having smallest bi first

    vector<pair<ll, ll>> residents;

    for (int i = 0; i < n; i++)
    {
        residents.push_back({b[i], a[i]});
    }

    sort(residents.begin(), residents.end()); // to get the increasing cost of bi

    ll totalCost = 0; // total cost

    totalCost += p; // Since first share must be from Pak

    // Using the cheapest shares available

    ll remaining = n - 1;

    for (auto &res : residents)
    {
        if (remaining == 0)
            break;

        ll cost = res.first;
        ll cnt = res.second;

        if (cost >= p)
            break;

        ll use = min(cnt, remaining);
        totalCost += use * cost;
        remaining -= use;
    }

    // If still someone is left uninformed, use Pak's shares
    if (remaining > 0)
        totalCost += remaining * p;

    return totalCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;

        vector<ll> a(n), b(n);

        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        cout << solve(p, a, b) << endl;
    }

    return 0;
}