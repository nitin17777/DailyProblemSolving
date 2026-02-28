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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        int cnt = 0;

        int maxi = *max_element(a.begin(), a.end());
        for (auto &x : a)
            if (x == maxi)
                cnt++;

        cout << cnt << endl;
    }
    return 0;
}