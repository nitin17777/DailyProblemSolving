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
        int n, y;
        cin >> n >> y;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        int su = accumulate(a.begin(), a.end(), 0);

        // since average would never chnage even after doing operation
        cout << ((su == a.size() * y) ? "Yes" : "No") << endl;
    }
    return 0;
}