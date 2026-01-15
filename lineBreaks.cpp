#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> &s, int m)
{
    /*
    1st strip can hold m characters while the second one can hold as many as needed

    Writes first x words from s on the first strip while remaining words are written in the second strip

    Return the max possible x such that all words s1 s2,..fit on the first strip of length m


    count the size of string -> IF size > rem => return cnt
    else cnt++ and move to the next string
    */

    int cnt = 0;

    for (auto &x : s)
    {
        if (x.size() > m)
        {
            return cnt;
        }

        else
        {
            m -= x.size();
            cnt++;
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
        int n, m;
        cin >> n >> m;

        vector<string> s(n);
        for (auto &x : s)
            cin >> x;

        cout << solve(s, m) << endl;
    }
    return 0;
}