#include <bits/stdc++.h>
using namespace std;

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{

    // guards[i] = [rowi, coli] and walls[j] = [rowj, colj]

    // A guard can see every cell in four cardinal directions unless obstructed by a wall or other guard

    // we have to return the number of unoccupied cells that are not guarded

    /*  0 = empty
        1 = guard
        2 = wall
        3 = guarded cell
    */

    vector<vector<int>> grid(m, vector<int>(n, 0));

    // walled cells marked

    for (auto &cell : walls)
    {

        grid[cell[0]][cell[1]] = 2;
    }

    for (auto &cell : guards)
    {
        grid[cell[0]][cell[1]] = 1;
    }

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    // Now marking visible area for each guards
    for (auto &g : guards)
    {
        int x = g[0], y = g[1];

        for (auto &d : dirs)
        {
            int nx = x + d.first, ny = y + d.second;

            while (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (grid[nx][ny] == 2 || grid[nx][ny] == 1)
                    break; // If there is wall or any guard

                if (grid[nx][ny] == 0)
                    grid[nx][ny] = 3; // mark it guarded

                nx += d.first;
                ny += d.second;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
                count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};

    cout << countUnguarded(4, 6, guards, walls) << endl;

    return 0;
}
