#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll s, ll k, ll m)
{
    /*
    Hourglass measures s mins,
    He flips this hourglass every k mins

    He needs to leave for errands in m mins

    Determine the mins sand will continue to fall after he leaves
    */

    // IF S>k :After 2k mins, no sand will be at the upper part -> So after every 2k mins 2k mins same amount of sand will be there in the upper half

    // If s <k : s minutes of sand will fall out and nothing would be left iin the upper half ->

    if (s <= k)
    {
        int time = m % k;
        return max(0LL, (s - time));
    }

    else
    {
        int time = m % (2 * k);

        if (time < k)
        {
            // Direct fall from s
            return s - time;
        }

        // Second Phase -> Falls from k after the flip

        else
            return k - (time - k);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll s, k, m;
        cin >> s >> k >> m;

        cout << solve(s, k, m) << endl;
    }
    return 0;
}