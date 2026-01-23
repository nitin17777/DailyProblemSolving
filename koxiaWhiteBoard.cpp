#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll> &a, vector<ll> &b)
{
    int n = a.size();
    int m = b.size();

    /*
    jth operation would be to choose  the boards and change the integr written on it to bj
    */

    vector<ll> arr;
    arr.reserve(n + m);

    for (auto &x : a)
        arr.push_back(x);
    for (auto &x : b)
        arr.push_back(x);

    sort(arr.begin(), arr.end());

    // now we have all elements in arr

    ll ans = 0;
    for (int i = m; i < n + m; i++)
    {
        ans += arr[i];
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
        int n, m;
        cin >> n >> m;

        vector<ll> a(n), b(m);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        cout << solve(a, b) << endl;
    }
    return 0;
}