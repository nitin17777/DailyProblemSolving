#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // we have to return the minimum time it takes for all the n nodes to receive the signal,if impossible return -1;

    // Building adjacency list first
    // adj[node] = list of {neighbour , weight}

    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &t : times)
    {
        int u = t[0], v = t[1], w = t[2];

        adj[u].push_back({v, w}); // edge u ->v with wwight w
    }

    vector<int> dist(n + 1, INT_MAX); // distance to each node->initially infinity

    dist[k] = 0; // distance to source itslef would be zero

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater < pair, int, int >>> pq;

    pq.push({0, k}); // starting from source node

    // Dijkstra's algo
    while (!pq.empty())
    {
        auto [time, node] = pq.top();
        pq.pop();

        if (time > dist[node])
            continue;
    }
}

int main()
{

    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << networkDelayTime(times, 4, 2);
    return 0;
}
