#include <bits/stdc++.h>
using namespace std;

int solve(string &s)
{
    int n = s.size();

    // In one move we can move one or two cells along the path

    // Return the max number of coins we can collect, avoiding to go thorns

    // We can move until 2 consective thorns come into our way

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '@')
            cnt++;

        if (s[i] == '*')
        {
            if (i + 1 < n && s[i + 1] == '*')
                return cnt;
        }
    }
    return cnt;
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
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}