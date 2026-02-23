#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // Return the min time it takes for all the nodes to receive the signal

    // times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time

    // If impossible to send signal to all the nodes,return -1

    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto &e : times)
    {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
    }

    // dist[i] = shortest distance from k to i
    vector<int> dist(n + 1, INT_MAX);

    dist[k] = 0; // since distance  to itself would be 0 obviosult

    // Min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Now starting from the source:
    pq.push({0, k});

    // Standard Dijkstra loop started
    while (!pq.empty())
    {
        auto [currDist, node] = pq.top();
        pq.pop();

        // IF distance is not equal to best known distance-> means the enty is outdated and we skip it
        if (currDist > dist[node])
            continue;

        // Relax all outgoing edges of this node
        for (auto &[nextNode, weight] : adj[node])
        {
            // If going through node gives shorter path to nexNode,update it
            if (dist[nextNode] > currDist + weight)
            {
                dist[nextNode] = currDist + weight;

                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // Find the max distance, because signal must reach all nodes,and last node to receive the signal determines the answer

    int maxTime = 0;
    for (int i = 1; i <= n; i++)
    {

        // In case we are unable to reach any node
        if (dist[i] == INT_MAX)
            return -1;

        maxTime = max(maxTime, dist[i]);
    }

    return maxTime;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << networkDelayTime(times, 4, 2);

    return 0;
}