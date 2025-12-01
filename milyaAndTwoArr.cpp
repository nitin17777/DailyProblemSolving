#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a, vector<int> &b)
{
    int n = a.size();

    set<int> sa(a.begin(), a.end());
    set<int> sb(b.begin(), b.end());

    if (sa.size() + sb.size() < 4)
        return false;
    else
        return true;
    /*
    if there are atleat 3 distinct elements in any array , answer would be yes
    */
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

        cout << (solve(a, b) ? "Yes" : "No") << endl;
    }

    return 0;
}