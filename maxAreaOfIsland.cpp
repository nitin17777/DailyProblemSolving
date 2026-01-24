#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
        return 0;

    grid[i][j] = 0; // Marking it as visited cell now

    return 1 + dfs(i + 1, j, grid) + dfs(i - 1, j, grid) + dfs(i, j - 1, grid) + dfs(i, j + 1, grid);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();

    // Area = no.o of cells with value 1 in island
    //  Return the max area

    /*
    Go to each cell check if any island in any direction is there
    */

    int maxArea = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                maxArea = max(maxArea, dfs(i, j, grid));
            }
        }
    }
    return maxArea;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}