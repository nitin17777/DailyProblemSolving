#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, int n, string curr, vector<string> &ans)
{
    if (curr.length() == 2 * n)
    {
        ans.push_back(curr);
        return;
    }

    // Adding the opening bracket
    if (open < n)
    {
        solve(open + 1, close, n, curr + '(', ans);
    }

    if (close < open)
    {
        solve(open, close + 1, n, curr + ')', ans);
    }
}

vector<string> generateParenthesis(int n)
{
    // We have to generate all pair of well formed parentheses
    vector<string> ans;
    solve(0, 0, n, "", ans);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> ans = generateParenthesis(3);

    for (auto &x : ans)
        cout << x << " ";

    cout << endl;
    return 0;
}