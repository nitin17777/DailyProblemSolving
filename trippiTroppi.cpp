#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<string> s(3);

        for (auto &x : s)
            cin >> x;

        string ans;

        for (auto &p : s)
        {
            ans += p[0];
        }
        cout << ans << endl;
    }
    return 0;
}
