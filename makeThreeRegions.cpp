#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>> &s)
{
    int n = s[0].size();

    // Each cell is either free or blocked

    // Cell y is reachable from cell x if: x and y share a side

    // there exists common free z between x and y

    // Return the number of free cells meeting the constraints:
    // If the cell is blocked, number of connected regions becomes exactly 3

    // This selected cell should share a side with all three regions, but in our given condition, one cell can share atmost 3 sides itself only

    // So we will search for pattern :  - # -    . _ .
    //      . - .    _ # _

    // Basically detecting  T pattern here

    int ans = 0;

    for (int i = 1; i < n - 1; i++)
    {
        bool ok = true;

        ok &= (s[0][i] == '.' && s[1][i] == '.'); // Mid col must be a vertical bridge

        ok &= (s[0][i - 1] != s[1][i - 1]); // ensuring only One free cell at left col

        ok &= (s[0][i + 1] != s[1][i + 1]); // Ensuring only one free cell at right col

        ok &= (s[0][i - 1] == s[0][i + 1]); // So that left and right cells are in same row)

        ans += ok;
    }
    return ans;
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

        vector<vector<char>> s(2, vector<char>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> s[i][j];
            }
        }
        cout << solve(s) << endl;
    }
    return 0;
}