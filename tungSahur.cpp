#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> compress(string &s)
{
    vector<pair<char, int>> blocks;

    int n = s.size();
    for (int i = 0; i < n;)
    {
        int j = i;

        while (j < n && s[j] == s[i])
            j++;

        blocks.push_back({s[i], j - i});
        i = j;
    }
    return blocks;
}

bool solve(string &s1, string &s2)
{
    /*
    A hit on left can sound  L or LL
    A hit onn right can sound R or RR

    p = sequence of hits made
    s = sequence of sounds heard


    Determine whether it is true that string s could have been the results fromm the string p

    */

    // p = LR, s = LLLR

    auto b1 = compress(s1);
    auto b2 = compress(s2);

    // number of compressed blocks should be same
    if (b1.size() != b2.size())
        return false;

    for (int i = 0; i < b1.size(); i++)
    {
        char c1 = b1[i].first;
        int k1 = b1[i].second;

        char c2 = b2[i].first;
        int k2 = b2[i].second;

        if (c1 != c2)
            return false;

        if (k2 < k1 || k2 > 2 * k1)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string p, s;
        cin >> p >> s;

        cout << (solve(p, s) ? "Yes" : "No") << endl;
    }
    return 0;
}