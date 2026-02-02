#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n)
{

    int S = (m * (m + 1)) / 2;

    // Removed all full rounds
    n %= S;

    for (int i = 1; i <= m; i++)
    {
        if (n < i)
            break;

        n -= i;
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    cout << solve(m, n) << endl;

    return 0;
}