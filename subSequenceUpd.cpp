#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int> &a, int l, int r)
{
    /*

    Operation: Choose any subseq and reverse it
    */
    int n = a.size();

    int k = r - l + 1;

    // Gives the min sum that can be obtained from left side
    vector<int> left, right;
    for (int i = 0; i < r; i++)
        left.push_back(a[i]);

    sort(left.begin(), left.end());
    ll sum1 = 0;
    for (int i = 0; i < k; i++)
        sum1 += left[i];

    for (int i = l - 1; i < n; i++)
    {
        right.push_back(a[i]);
    }

    // Min sum we can obtain from right side
    sort(right.begin(), right.end());

    ll sum2 = 0;
    for (int i = 0; i < k; i++)
        sum2 += right[i];

    return min(sum1, sum2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a, l, r) << endl;
    }
    return 0;
}