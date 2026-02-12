#include <bits/stdc++.h>
using namespace std;

int longestBalanced(string s)
{
    int n = s.size();

    // A substring is balanced if all distinct chars in the substring appear same number of times

    int ans = 0;

    /// Return the longest balanced substring of s
    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0);

        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            int mn = INT_MAX, mx = 0;

            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 0)
                {
                    mn = min(mn, freq[k]);
                    mx = max(mx, freq[k]);
                }
            }
            if (mn == mx)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << longestBalanced("abbac") << endl;
    return 0;
}