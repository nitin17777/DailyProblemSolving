#include <bits/stdc++.h>
using namespace std;

int solve(string s, int k)
{
    int n = s.size();

    int cnt = 0;

    // i = 1 => skip it including next k classes

    for (int i = 0; i < n;)
    {
        if (s[i] == '1')
        {
            i = min(i + k + 1, n);
        }

        else
        {
            cnt++;
            i++;
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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        cout << solve(s, k) << endl;
    }
    return 0;
}