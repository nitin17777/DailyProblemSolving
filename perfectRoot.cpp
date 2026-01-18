#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n)
{
    vector<int> ans;

    for (int i = 1; i <= n; i++)
        ans.push_back(i);

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