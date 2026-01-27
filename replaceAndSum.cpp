#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, vector<int> &b, int l, int r)
{
    /*

    he can perform following operations:

    Choose index i and replace ai with ai+1
    choose index i and replae ai with bi

    Find the max value of sum for each query

    */
    int n = a.size();

    vector<int> best(n);
    best[n - 1] = max(a[n - 1], b[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        best[i] = max({best[i + 1], a[i], b[i]});
    }

    // Atlast finding sum in the given range
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + best[i];
    }

    return pref[r] - pref[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            cout << solve(a, b, l, r) << " ";
        }
        cout << endl;
    }
    return 0;
}