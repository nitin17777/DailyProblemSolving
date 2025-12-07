#include <bits/stdc++.h>
using namespace std;

int solve(string s, int k)
{
    int n = s.size();
    int cnt = 0;

    // i = 1 => skip it including next k classes

    vector<bool> check(n, false);

    // mark every class in which we can sleep

    int i = 0;
    while (i < n)
    {
        if (s[i] == '1')
        {
            i += (k + 1);
        }
        else // when 0 is encontered
        {
            check[i] = true;
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (check[i] == true)
            cnt++;
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