#include <bits/stdc++.h>
using namespace std;

int solve(string s, int k)
{
    int n = s.length();

    /*

    In one operation:
    She can change upper to lower or lower to upper


    Find the max price that can be obtained

    k = Number of operation that can be performed

    */

    unordered_map<char, int> freq;
    for (auto &x : s)
        freq[x]++;

    int pairs = 0;

    // Now cancel the uppercase and lowercase letters
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int low = freq[ch];
        int up = freq[ch - 'a' + 'A'];

        // Adding the matching pairs to our answer
        pairs += min(low, up);

        // Calculating extra pairs
        int extra = abs(low - up);

        // Applying the operation
        int add = min(k, extra / 2);
        pairs += add;
        k -= add;
    }
    return pairs;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        cout << solve(s, k) << endl;
    }
    return 0;
}