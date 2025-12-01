#include <bits/stdc++.h>
using namespace std;

int maxi(int n, int y, int r)
{
    /*
    A player can be suspended : 2y or 1r

    2 yellow  = 1
    1 Red = 1
    */

    int Y = y / 2;
    int ans = Y + r;
    if (ans >= n)
        return n;

    else
        return Y + r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, y, r;
        cin >> n >> y >> r; // y +r <= 2n

        cout << maxi(n, y, r) << endl;
    }

    return 0;
}