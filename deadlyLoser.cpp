#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int sx, int sy, int d)
{
    // In one step it can move to any adjacent cell

    // If they come to cell with distance <= d it gets evaporated

    // Return least number of cells to reach (n,m) else -1

    // Block all cells nearby and including the one containing laser

    // Now find the path

    if (min(sx - 1, m - sy) <= d && min(n - sx, sy - 1) <= d)
        return -1;

    else
        return n + m - 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, o, p, q;
        cin >> n >> m >> o >> p >> q;

        cout << solve(n, m, o, p, q) << endl;
    }
    return 0;
}