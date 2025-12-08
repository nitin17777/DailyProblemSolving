#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a, int k)
{
    /*

    These conditions must hold

    For each 1<=i<=n, atleast one divisor of ai is contained in B

    For each 1<=i<=m all posiitive multiples of bj which are less than or equal to k appear in array a at least once


    Find the complete set B and if no such B exists return -1 simply

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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        vector<int> ans = solve(a, k);

        if (ans.empty())
            cout << -1 << endl;

        else
        {
            cout << ans.size();
            for (auto &an : ans)
                cout << an << " ";

            cout << endl;
        }
    }
    return 0;
}