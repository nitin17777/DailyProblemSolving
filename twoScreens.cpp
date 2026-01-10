#include <bits/stdc++.h>
using namespace std;

int solve(string s, string t)
{
    /*
    In one second, we can do :

    Calculate the min numnber of seconds we have to spend so that first screen displays the sequence s and second screen displays the sequence t;
    */

    /*

    As soon as there is first difference in strings, from that point write separately in both ->
    */
    int n = s.size(), m = t.size();

    int i = 0;

    // Length of min common substring
    while (i < min(m, n) && s[i] == t[i])
        i++;

    int fs1 = n - i; // 0
    int fs2 = m - i; // 7

    if (i > 0)
        return fs1 + fs2 + 1 + i;

    else
        return fs1 + fs2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string n, m;
        cin >> n >> m;

        cout << solve(n, m) << endl;
    }
    return 0;
}