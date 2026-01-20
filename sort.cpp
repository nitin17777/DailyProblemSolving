#include <bits/stdc++.h>
using namespace std;

/* BRUTE FORCE KIND OF
int solve(string a, string b, int l, int r)
{
    l--;
    r--;




    In one operation, we can select l<i<r and set ai= x

    Return the min number of ops required such that: sorted(a[l...r] = b[l...r])


    // For each query check how many mismatches are there -> same number of occurences of characters

    string s1 = a.substr(l, r - l + 1);
    string s2 = b.substr(l, r - l + 1);

    unordered_map<char, int> m1, m2;
    for (auto &x : s1)
        m1[x]++;
    for (auto &x : s2)
        m2[x]++;

    int ans = 0;
    for (auto &p : m1)
    {
        char c = p.first;
        int cntA = p.second;

        int cntB = m2[c];
        if (cntA > cntB)
        {
            ans += (cntA - cntB);
        }
    }
    return ans;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        // pre[i][c] = number of times char c appears in a[1..i]
        vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++)
        {
            pre1[i] = pre1[i - 1]; // copying previous prefix first

            // And increasing current char's frequency now
            pre1[i][a[i - 1] - 'a']++;
        }

        // Building same prefix frequency for string B too
        vector<vector<int>> pre2(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++)
        {
            pre2[i] = pre2[i - 1]; // copying previous prefix first

            // And increasing current char's frequency now
            pre2[i][b[i - 1] - 'a']++;
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int diffSum = 0;

            for (int c = 0; c < 26; c++)
            {
                // Frequency of char c in a[l...r]
                int freqA = pre1[r][c] - pre1[l - 1][c];
                int freqB = pre2[r][c] - pre2[l - 1][c];

                diffSum += abs(freqA - freqB);
            }
            cout << diffSum / 2 << endl;
        }
    }
    return 0;
}