#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k, string s)
{
    // Select any segment of length k instantly and turn all elements into one

    // Min number of time he need to use this ability to keep up
    // No interval of m consecutive spots is consists of 0

    // iterate till we find 'm' consecutive zeroes
    vector<int> ps(n, 0);

    int ans = 0; // total actions performed
    int cnt = 0; // current count of consecutive '0'
    int sum = 0; // keeps track of current cooldown

    for (int i = 0; i < n; i++)
    {
        sum += ps[i];

        if (sum || s[i] == '1')
            cnt = 0; // since now consecutive zero streak is broken down

        // or zeroes streak is still going on
        else
        {
            cnt++;
            if (cnt == m)
            {
                sum++, ans++, cnt = 0;

                if (i + k < n)
                    ps[i + k]--;
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k, s;
        cin >> n >> m >> k >> s;

        cout << solve(n, m, k, s);
    }
    return 0;
}
