#include <bits/stdc++.h>
using namespace std;

int solve(int m, string &s)
{
    /*

    Planning to hold m rounds next month and each round should contain one problem of difficulty levels : ABCDEFG

    ith problem has difficulty level ai


    find min number of problems he needs to come with up to hold m rounds
    */

    int cnt = 0;

    unordered_map<char, int> freq;
    for (auto &x : s)
        freq[x]++;

    for (char ch = 'A'; ch <= 'G'; ch++)
    {
        if (freq[ch] < m)
        {
            cnt += (m - freq[ch]);
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

        string s;
        cin >> s;

        cout << solve(m, s) << endl;
    }
    return 0;
}