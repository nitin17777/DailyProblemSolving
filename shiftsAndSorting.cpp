#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(string &s)
{
    /*
    in one operation choose any substring and cyclically shift it
    And cost of such operation is: r-l+1

    Return the minimum total cost to make s sorted in descending order
    */

    int n = s.size();

    // Counting number of zeroes first
    int zeroes = 0;
    for (char c : s)
    {
        if (c == '0')
            zeroes++;
    }

    // cnt[0] = zeroes seen so far
    // cnt[1] = ones seen so far

    int cnt[2] = {0, 0};
    ll ans = 0;

    for (char ch : s)
    {
        int c = ch - '0';
        cnt[c]++;

        if (c == 0)
        {
            // if atleast one '1' appeared before this '0'
            if (cnt[1] > 0)
                ans += 1;
        }

        else
        {
            //  when c == 1
            // Count zeroes that appear after this '1'
            ans += (zeroes - cnt[0]);
        }
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
        string n;
        cin >> n;

        cout << solve(n) << endl;
    }
    return 0;
}