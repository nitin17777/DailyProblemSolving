#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &mat)
{
    /*
    We can :
            Choose two columns and swap them

    After performing this operation, choose a path from cell(1,1) -> (2,n)
    In each move we must move forward either in row or col

    Return the max possible sum of this path
    */

    // to the left of our path change column: Place the cols for which upper value is greater than lower value and to the right of this path change col place the row with values with greater lower values

    int n = mat[0].size();

    int ans = INT_MIN;

    // finding max val

    for (int j = 0; j < n; j++)
    {
        int pathChangeSum = mat[0][j] + mat[1][j];

        for (int k = 0; k < n; k++)
        {
            if (k == j)
                continue;

            pathChangeSum += max(mat[0][k], mat[1][k]);
        }
        ans = max(ans, pathChangeSum);
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

        vector<vector<int>> m(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }

        cout << solve(m) << endl;
    }
    return 0;
}