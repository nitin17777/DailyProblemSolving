#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int d)
{
    // calculate the min number of towers he can achieve given that all n boxes should be used

    // Weight of all boxes above that box must not exceed durability of that box

    // all separate towers in this case
    if (m > d)
        return n;

    int maxi = (d / m) + 1;

    return (n + maxi - 1) / maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, d;
        cin >> n >> m >> d;

        cout << solve(n, m, d) << endl;
    }
    return 0;
}