#include <bits/stdc++.h>
using namespace std;
#define ll long long

int minCost(vector<vector<int>> &grid, int k)
{
    int m = grid.size(), n = grid[0].size();
    const ll INF = 1e18;

    /*
    Our goal is to reach (m-1,n-1) cell

    We have 2 types of available moves:
    1. We can move right or down from current position and cost =  vlaue fo that destination cell

    2. Teleport from (i,j) to (x,y) such that grid[x][y] <= grid[i][j] and cost of this move = 0,and we may do this move at most k times

    Return the min cost to reach that final cell
    */

    // prev[i][j] = cost to reach (i,j) using t-1 teleports
    vector<vector<ll>> prev(m, vector<ll>(n, INF));

    // prev[i][j] = cost to reach (i,j) using t teleports
    vector<vector<ll>> curr(m, vector<ll>(n, INF));

    prev[0][0] = 0; // starting position

    // Pre storing all cells with their values
    vector<pair<int, int>> cells;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cells.push_back({i, j});
        }
    }

    // custom sorting on basis of descending order of grid value
    sort(cells.begin(), cells.end(), [&](auto &a, auto &b)
         { return grid[a.first][a.second] > grid[b.first][b.second]; });

    // Iterating over number of teleports used
    for (int t = 0; t <= k; t++)
    {
        // Reseting current dp
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                curr[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // Starting cell
                if (i == 0 && j == 0)
                {
                    curr[i][j] = min(curr[i][j], prev[i][j]);
                    continue;
                }

                // Moving from top
                if (i > 0)
                {
                    curr[i][j] = min(curr[i][j], curr[i - 1][j] + grid[i][j]);
                }

                // Moving from left
                if (j > 0)
                {
                    curr[i][j] = min(curr[i][j], curr[i][j - 1] + grid[i][j]);
                }
            }
        }
        if (t > 0)
        {
            ll best = INF;

            for (auto &cell : cells)
            {
                int i = cell.first;
                int j = cell.second;

                best = min(best, prev[i][j]);

                curr[i][j] = min(curr[i][j], best);
            }
        }
        prev.swap(curr);
    }
    return (int)prev[m - 1][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> g = {{1, 3, 3}, {2, 5, 4}, {4, 3, 5}};
    cout << minCost(g, 2) << endl;

    return 0;
}