#include <bits/stdc++.h>
using namespace std;

int minCostConnectPoints(vector<vector<int>> &points)
{
    // Return the min cost to make all the points connnected

    int n = points.size();

    // Min cost to connect point i to the current MST
    vector<int> minDist(n, INT_MAX);

    // To check if i is already included in MST
    vector<bool> inMST(n, false);

    int total = 0;

    minDist[0] = 0; // Starting from point 0, though we can start from any point

    for (int i = 0; i < n; i++)
    {
        int u = -1;

        // Pick the node not yet in MST with the smallest connection lost
        for (int j = 0; j < n; j++)
        {
            if (!inMST[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        inMST[u] = true; // Include this node in MST

        // Adding this connection cost to out answer
        total += minDist[u];

        // Now try connecting this to all other nodes
        for (int v = 0; v < n; v++)
        {
            if (!inMST[v])
            {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                minDist[v] = min(minDist[v], dist);
            }
        }
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    cout << minCostConnectPoints(points) << endl;

    return 0;
}