#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());

    int ans = a[0];

    for (int i = 1; i < n; i++)
    {
        ans = (ans + a[i]) / 2;
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a) << endl;
    }
    return 0;
}