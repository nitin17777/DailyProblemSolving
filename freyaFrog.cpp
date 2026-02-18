#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int x, int y, int k)
{
    // Return min moves required to land on point (x,y)
    // At each step he must alter

    ll yy = (y + k - 1) / k; // ceil divisionn
    ll xx = (x + k - 1) / k;

    if (yy >= xx)
        return 2 * yy;
    else
        return 2 * xx - 1; // Removing the extra movement in y axis in case xx is greater, since we will already be at our destination by then
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        cout << solve(x, y, k) << endl;
    }
    return 0;
}