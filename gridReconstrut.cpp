#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n)
{
    /*

    Stop at (2,n)

    Cost = a1 - a2 + a3......Alternating sum

    Construct a way to place 1,2,3...2n integers on the grid such that minimum cost over all the paths is maximised

    if i is even, a[1,i] = i and a[2][i] = i-1

    Values to be added should be large as possible
    And to be subtracted should be as small as possible, to maximise the total sum
    */

    vector<vector<int>> a(2, vector<int>(n, 0));

    // Initial placings to maximise at edges atleast
    a[0][0] = 2 * n - 1;
    a[1][n - 1] = 2 * n;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            a[0][i - 1] = i;
            a[1][i - 2] = i - 1;
        }
        else
        {
            a[0][i - 1] = n + i - 1;
            a[1][i - 2] = n + i - 2;
        }
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> ans = solve(n);

        for (auto &an : ans)
        {
            for (auto &x : an)
                cout << x << " ";

            cout << endl;
        }
    }
    return 0;
}