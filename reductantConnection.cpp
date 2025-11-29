#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, int target, vector<vector<int>> &adj, vector<bool> &visited)
{
    if (src == target)
        return true;

    visited[src] = true;

    for (auto nei : adj[src])
    {
        if (!visited[nei])
        {
            if (dfs(nei, target, adj, visited))
                return true;
        }
    }
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    // we have to return an edge that can be removed so that resulting graph is tree of n nodes

    int n = edges.size();

    vector<vector<int>> adj(1001); // adjacency list

    for (auto &e : edges)
    {
        int u = e[0], v = e[1];

        vector<bool> visited(1001, false);

        // checkng if path u to v already exists before adding edge
        if (!adj[u].empty() && !adj[v].empty())
        {
            if (dfs(u, v, adj, visited))
                return e; // this edge makes cycle if already connected
        }

        // Otherwise they are safe to add the edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return {};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> ans = findRedundantConnection(edges);
    for (auto &an : ans)
        cout << an << " ";

    cout << endl;

    return 0;
}