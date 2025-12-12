#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int k)
{
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