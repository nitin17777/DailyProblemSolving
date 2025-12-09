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

        int odd = 0, even = 0;
        for (auto &x : a)
        {
            if (x & 1 == 1)
                odd++;

            else
                even++;
        }

        if (even > 0)
            cout << odd + 1 << endl;

        else
            cout << odd - 1 << endl;
    }

    return 0;
}