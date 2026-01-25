#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n, q;

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