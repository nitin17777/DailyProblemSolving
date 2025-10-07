#include <bits/stdc++.h>

using namespace std;

int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();

    // each cell represents the elevation at that point (i,j)

    // at time t, the water level is t, means every cell with elevation less than equal to t is submerged

    // we can swim from a sqaure to another 4 directions if and only if elevation if both squares are individually at most t

    // return the min time until you reach the bottom right sqaure

    // ALGO :

    // check all the nighbours
    // if all neighbours are greater , add time=min(all neighbours) and move to that neighbour

    // to mark that current cell is visited
    vector<vector<int>> visited(n, vector<int>(n, 0));

    // we will be making a min heap to store {elevation,row,col}

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // initiallising our min heap
    pq.push({grid[0][0], 0, 0});
    visited[0][0] = 1;

    // now setting up our directions
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxElev = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int elev = top[0], i = top[1], j = top[2];
        maxElev = max(maxElev, elev);

        // The moment when we finally reach our destination
        if (i == n - 1 && j == n - 1)
            return maxElev;

        // now exploring other neighbours

        for (auto &dir : dirs)
        {
            int x = i + dir[0], y = j + dir[1];

            if (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y])
            {
                visited[x][y] = 1;

                pq.push({grid[x][y], x, y});
            }
        }
    }
    return -1;
}

int main()
{

    vector<vector<int>> grid = {{0, 2}, {1, 3}};

    cout << swimInWater(grid) << endl;

    return 0;
}
