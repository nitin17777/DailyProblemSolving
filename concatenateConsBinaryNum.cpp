#include <bits/stdc++.h>
using namespace std;
#define ll long long

int concatenatedBinary(int n)
{
    // Concatenate nums from 1 to n,  and return the number formed

    const int MOD = 1e9 + 7;

    ll ans = 0;
    int bits = 0;
    for (int i = 1; i <= n; i++)
    {

        if ((i & (i - 1)) == 0)
            bits++;
        s

            // Shift left and add i
            ans = ((ans << bits) | i) % MOD;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << concatenatedBinary(3) << endl;

    return 0;
}