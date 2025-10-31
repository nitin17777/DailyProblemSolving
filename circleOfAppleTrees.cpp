#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> apples(n);
        for (auto &x : apples)
            cin >> x;

        set<int> app;
        for (auto x : apples)
        {
            app.insert(x);
        }

        cout << app.size() << endl;
    }

    return 0;
}
