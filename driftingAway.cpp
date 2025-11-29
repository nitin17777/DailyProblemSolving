#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;

        cin >> s;

        int n = s.size();
        /*

        < => Leftward Current
        > => RightWard Current
        * => No Current


        ALGO:
        if there is something like : ><,answer will be -1,as he can get stuck forever.

        And if no such pattern is there, then all <<< must appear before >>>

        and simply the return the arrow with max count

        if string is like : <<<<.....<<>>..>>>> => max number of ether arrows would be the answer

        replace each * with < or > to maximise the sailing length without creaitng any < substring
        */

        bool bad = false;

        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] != '<' && s[i + 1] != '>')
            {
                bad = true;
                break;
            }
        }

        if (bad)
        {
            cout << -1 << endl;
            continue;
        }

        int cntL = count(s.begin(), s.end(), '<');
        int cntR = count(s.begin(), s.end(), '>');

        int ans = n - min(cntL, cntR);
        cout << ans << endl;
    }
    return 0;
}
