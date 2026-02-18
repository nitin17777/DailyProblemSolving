#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<int> &a, int k)
{
    int n = a.size();

    // Score = A - B

    // Alice ->Maximise and  Bob -> Minimise

    // Bob can increase the cost by x <= k

    // Return the min possible final score Bob can achieve

    sort(a.rbegin(), a.rend());

    ll score = 0;

    for (int i = 0; i < n - 1; i += 2)
    {
        ll diff = a[i] - a[i + 1];

        ll reduce = min((ll)k, diff);

        score += diff - reduce;
        k -= reduce;
    }

    if (n % 2 != 0)
    {
        score += a[n - 1];
    }
    return score;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a, k) << endl;
    }
    return 0;
}