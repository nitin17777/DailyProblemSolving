#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
        return;

    // marking that grid 0 otherwise
    grid[i][j] = 0;

    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
}

int numEnclaves(vector<vector<int>> &grid)
{
    // Return the nnumebr of land cells in grid from which we cannot walk off the boundary in any number of moves

    // if through some cell, we can go out of boundary,then we can go out through every connected land piece to it

    int m = grid.size();
    int n = grid[0].size();

    // Removing boundary connected land pieces

    for (int i = 0; i < m; i++)
    {
        dfs(i, 0, grid);
        dfs(i, n - 1, grid);
    }

    for (int j = 0; j < n; j++)
    {
        dfs(0, j, grid);
        dfs(m - 1, j, grid);
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                ans++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << numEnclaves(grid) << endl;

    return 0;
}