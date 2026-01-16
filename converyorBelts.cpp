#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x1, int y1, int x2, int y2)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        cout << solve(n, x1, y1, x2, y2) << endl;
    }
    return 0;
}