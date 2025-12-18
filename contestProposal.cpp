#include <bits/stdc++.h>
using namespace std;

int mini(vector<int> &a, vector<int> &b)
{
    // difficulty of ith problem is atmost bi.

    // We alrady have nn proposals and difficulty of ith problem is ai
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

        vector<int> a(n), b(n);

        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        cout << mini(a, b) << endl;
    }

    return 0;
}