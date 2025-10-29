#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(ll a, ll b, ll k)
{
    // choose dx and dy from {0 to k} inclusive

    // She can move dx cells to left and dy cells down : Move robot from (x,y) to (x-dx, y-dy)

    // cost of operation would be : 1 if chosen pair is used for first time and : 0 if pair has been choosen before

    // we can look up to this question as : we need to cover distance (a,b) repeatedly using (dx,dy) 't' times

    // and t must be a common divisor of a and b + (a/t <= k && b/t <= k)
    //  So : a = t * dx;
    //       b = t * dy

    // so (dx,dy)must be such that both a and b are multiples of same integer t

    // if such t exists , cost = 1 , otherwise cost = 2

    ll gg = __gcd(a, b);

    if (a / gg <= k && b / gg <= k)
        return 1;
    else
        return 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, k;
        cin >> a >> b >> k;
        cout << solve(a, b, k) << endl;
    }
    return 0;
}
