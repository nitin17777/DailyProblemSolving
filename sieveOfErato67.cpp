#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a)
{
    int n = a.size();

    for (auto &x : a)
    {
        if (x == 67)
            return true;
    }
    return false; // d
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

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << (solve(a) ? "Yes" : "No") << endl;
    }
    return 0;
}