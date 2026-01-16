#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n)
{
    /*
    sum of elements at k multiples is a multiple of k

    Return this beautiful array

    */

    vector<int> ans;
    // vector<int> ans(n,0);

    // for (int i = 0; i < n; i++)
    // {
    //     ans[i] = (i + 1) * (i + 1);
    // }

    // Or more simply:

    for (int i = 0; i < n; i++)
    {
        ans.push_back(i + 1);
    }
    return ans;
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

        vector<int> ans = solve(n);
        for (auto &an : ans)
            cout << an << " ";

        cout << endl;
    }
    return 0;
}