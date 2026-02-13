#include <bits/stdc++.h>
using namespace std;

int surfaceArea(vector<vector<int>> &grid)
{
    int n = grid.size();
    int area = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v = grid[i][j];

            if (v > 0)
            {
                area += 4 * v + 2; // Full tower surface

                if (i > 0) // Removing overlap with top cell
                {
                    area -= 2 * min(v, grid[i - 1][j]);
                }

                if (j > 0) // Removing overlap with left cell
                {
                    area -= 2 * min(v, grid[i][j - 1]);
                }
            }
        }
    }
    return area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    cout << surfaceArea(grid) << endl;

    return 0;
}