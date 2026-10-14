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
        int n, k;
        cin >> n >> k;

        vector<int> freq(n + 2, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x <= n) freq[x]++;   // values > n can never affect the mex
        }

        bool alice = false;
        for (int v = 0; v <= n + 1; v++)
        {
            if (freq[v] >= 2LL * k) continue;
            alice = (freq[v] == 2LL * k - 1);
            break;
        }
        cout << (alice ? "Yes" : "No") << '\n';
    }
    return 0;
}