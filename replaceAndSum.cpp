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
        cin >> n >> q;

        vector<int> a(n + 5), b(n + 5), pref(n + 5);

        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];

        a[n + 1] = 0;

        for (int i = n; i > 0; i--)
        {
            a[i] = max({a[i + 1], a[i], b[i]});
        }

        pref[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + a[i];
        }

        for (int i = 1; i <= q; i++)
        {
            int L, R;
            cin >> L >> R;
            cout << pref[R] - pref[L - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}