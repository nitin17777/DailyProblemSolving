#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int n)
{
    // find min k such that n is divisor of k^n

    // We just have to make sure: every prime dividing n appears in k

    // Ans = prodcut of distinct prime factors of nn

    ll k = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            k *= i;

            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        k *= n;

    return k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}