#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        ll c;
        cin >> n >> c;

        vector<ll> a(n+1); // 1-indexed: a[1..n]
        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<ll> dp(n+1);
        dp[0] = 0;
        if(n >= 1)
        {
            dp[1] = a[1] - c;
        }

        for(int i = 2; i <= n; i++)
        {
            ll opt1 = dp[i-1] + a[i] - c;
            ll opt2 = dp[i-2] + max(a[i-1], a[i]) - c;
            dp[i] = max(opt1, opt2);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}