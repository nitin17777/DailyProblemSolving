#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a, int s, int x)
{

    int su = accumulate(a.begin(), a.end(), 0);

    if (su > s)
        return false;

    int diff = abs(s - su);

    if (diff % x == 0)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, s, x;
        cin >> n >> s >> x;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        cout << (solve(a, s, x) ? "Yes" : "No") << endl;
    }

    return 0;
}