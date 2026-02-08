#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n, ll w)
{

    // Determine the max number of boards that can be removed

    // So we can leave space < k and removed the unwanted boards, and return

    // w-1 consective spaces can only be there, no more than that, and we have to maximise how many times these w-1 could occur
    return (n / w) * (w - 1) + min(n % w, w - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        cout << solve(n, w) << endl;
    }
    return 0;
}