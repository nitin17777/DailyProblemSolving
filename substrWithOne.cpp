#include <bits/stdc++.h>
using namespace std;

int numSub(string s)
{
    /*
    We have to return the substrings that consists fo all '1's

    */

    int n = s.size();
    const long long MOD = 1e9 + 7;
    int ans = 0;
    int k = 0;
    int i = 0;

    while (i < n)
    {
        if (s[i] == '1')
            k++;
        else // when we find '0'
        {

            if (k != 0)
            {
                ans += (k * (k + 1)) / 2; // to make out of consecutive '1's
                k = 0;                    // reset k count
            }
        }
        i++;
    }
    if (k > 0)
        ans = (ans + ((k * (k + 1)) / 2) % MOD) % MOD;

    return ans;
}

int main()
{
    cout << numSub("0110111") << endl;
    return 0;
}
