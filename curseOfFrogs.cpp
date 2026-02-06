#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll x, vector<ll> &a, vector<ll> &b, vector<ll> &c)
{
    int n = a.size();
    /*

    ith type of jump allows to jump forward by not more than ai units
    If it was on point k, then after the jump it can land at ai+k

    Before the use of ith type of jump, they roll back to ci units

    Frog's goal is to reach number x

    Find the min number of rollbacks it will have to endure on it's way to the goal , if can't reach, return -1;

    Before the use of every bith jump rollback happens, and we have to count those number of rollbacks until it reaches the destination


    ith type of jump can be used bi - 1 times without any rollback, as we are safe until we have to make the bith jump

    so distance gained = ai * (bi-1)
    and let r denote the remaining distance now

    if r <= 0 Means the frog has reached the target

    so for every ai* bi we cover, we go ci back
    */

    ll start = 0;
    ll mx = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, a[i] * b[i] - c[i]);
        start += a[i] * (b[i] - 1);
    }
    x -= start;

    if (x <= 0)
        return 0;

    if (mx <= 0)
        return -1;

    return (x + mx - 1) / mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;

        vector<ll> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        cout << solve(x, a, b, c) << endl;
    }
    return 0;
}