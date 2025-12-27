#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid)
{
    /*

    1-> Represents land
    0-> Represents water

    Grid cells are not connected diagonally, and grid is compeletly surrounded by water and there is exactly one island

    Determine the perimeter of the island

    */

    int rows = grid.size();
    int cols = grid[0].size();

    int peri = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                peri += 4;

                // left check
                if (i > 0 && grid[i - 1][j] == 1)
                    peri--;

                // right check
                if (i < rows - 1 && grid[i + 1][j] == 1)
                    peri--;

                // up check
                if (j > 0 && grid[i][j - 1] == 1)
                    peri--;

                // down check
                if (j < cols - 1 && grid[i][j + 1] == 1)
                    peri--;
            }
        }
    }

    return peri;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grids = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    cout << islandPerimeter(grids) << endl;

    return 0;
}