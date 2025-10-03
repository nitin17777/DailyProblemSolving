#include <bits/stdc++.h>
using namespace std;

int trapRainWater(vector<vector<int>> &heightMap)
{
    // we have a height of each unit cell in a 2D elevatiion map , return the volume of water it can trap after raining

    // water can only be stored if it's surrounded by higher walls

    // lowest boundary determines how much water can be trapped inside

    int m = heightMap.size();
    if (m == 0)
        return 0;

    int n = heightMap[0].size();
    if (n == 0)
        return 0;

    // Tracking visited cell to avoid double processing

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // min heap(priority_queue) to always expand the lowest boundary first
    // each element is : {height, row,col}

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // pushing all boundary cells into heap
    // and each element would be {height,row,col}
    for (int i = 0; i < m; i++)
    {
        pq.push({heightMap[i][0], i, 0});         // left boundary
        pq.push({heightMap[i][n - 1], i, n - 1}); // right boundary
        visited[i][0] = visited[i][n - 1] = true;
    }

    for (int j = 0; j < n; j++)
    {
        pq.push({heightMap[0][j], 0, j}); // top boundary

        pq.push({heightMap[m - 1][j], m - 1, j}); // bottom boundary

        visited[0][j] = visited[m - 1][j] = true;
    }

    // directions for moving up, down , left, right
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int water = 0;

    // processing heap until all cells are visited

    while (!pq.empty())
    {
        auto cell = pq.top();

        pq.pop();

        int h = cell[0]; // boundary height currently
        int x = cell[1];
        int y = cell[2];

        for (auto &d : dirs)
        {
            int nx = x + d[0];
            int ny = y + d[1];

            // skipping invalid or already visited cells
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                continue;

            visited[nx][ny] = true;

            // if neighbour height is lower, water can be trapped
            // And trapped = boundary height  - neighbour height

            if (heightMap[nx][ny] < h)
            {
                water += h - heightMap[nx][ny];
            }
            pq.push({max(h, heightMap[nx][ny]), nx, ny});
        }
    }
    return water;
}

int main()
{

    vector<vector<int>> heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};

    cout << trapRainWater(heightMap) << endl;

    return 0;
}
