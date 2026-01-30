#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{

    int n = s.length();

    /*

    In one move: we can delete one chracter from s and operation costs 1 coin

    Swap any pair of characters in s and this operation is free

    Min total cost to make the string t good

    String t is good if for each i: ti != si


    */

    int cnt[2] = {0, 0};
    for (char c : s)
    {
        cnt[c - '0']++;
    }

    for (int i = 0; i <= n; i++)
    {

        // If reached the end or we are out of required opposite bits
        if (i == n || cnt[1 - (s[i] - '0')] == 0)
            return n - i; // == Deletions needed.

        cnt[1 - (s[i] - '0')]--;
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
        string n;
        cin >> n;

        cout << solve(n) << endl;
    }
    return 0;
}