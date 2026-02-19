#include <bits/stdc++.h>
using namespace std;

int countBinarySubstrings(string s)
{
    int n = s.size();

    // Return the number of substring having same number of 0s and 1s
    // All 0s and 1s are grouped together consecutively

    // Till every index, count the number of consecutive zeroes and ones and take their minimum

    // At every index, count number of consective zeroes and ones, and take their in

    int prev = 0; // Length of previous group
    int curr = 1; // Length of current group
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            curr++;

        else
        {
            ans += min(prev, curr);
            prev = curr;
            curr = 1;
        }
    }

    ans += min(prev, curr); // Last group
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << countBinarySubstrings("00110011") << endl;

    return 0;
}