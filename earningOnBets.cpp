#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    int n = a.size();

    // Total number of coins that will be received back > total coins used for the bet
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

        vector<int> ans = solve(a);

        if (ans.empty())
            cout << -1 << endl;

        else
        {
            for (auto &x : ans)
                cout << x << " ";
        }
        cout < endl;
    }
    return 0;
}