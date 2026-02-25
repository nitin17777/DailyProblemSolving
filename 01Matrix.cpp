#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    // For each cell return the distance of nearest 0 for each cell

    // Make a dp matrix consisting of this closest distance from 0

    // For every cell find the min possible distance

    vector<vector<int>> dist(m, vector<int>(n, -1));

    queue<pair<int, int>> q;

    // Pushing all 0s into the queue
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // Start BFS
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        // Exploring all neighbouring cells
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> m = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> ans = updateMatrix(m);

    for (auto &an : ans)
    {
        for (auto &a : an)
            cout << a << " ";

        cout << endl;
    }
    return 0;
}