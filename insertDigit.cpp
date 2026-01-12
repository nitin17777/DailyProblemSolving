#include <bits/stdc++.h>
using namespace std;

string solve(string s, char d)
{
    int n = s.size();

    // insert the digit at position before the number that is smaller than d

    for (int i = 0; i < n; i++)
    {
        if (s[i] < d)
        {
            // insert at this inndex
            s.insert(s.begin() + i, d);
            break;
        }
    }
    if (s.size() != n + 1)
    {
        return s + d;
    }

    return s;
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
        char d;
        string s;

        cin >> d >> s;

        cout << solve(s, d) << endl;
    }
    return 0;
}