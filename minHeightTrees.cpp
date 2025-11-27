#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{

    // edges[i] = a[i],b[i] =>There is an undirected edge between two nodes ai and bi in the tree

    if (n == 1)
        return {0};

    // building adjacency list
    vector<vector<int>> adj(n);

    vector<int> degree(n, 0);

    for (auto &e : edges)
    {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);

        degree[u]++; // counting number of edges touching u
        degree[v]++; // counting number of edges touching v
    }

    queue<int> q;

    // pushing all leaves into queue (i.e all nodes with degree one)

    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            q.push(i);
    }

    int rem = n;

    // Removing leaf layers unntil <=2 nodes are left
    while (rem > 2)
    {
        int leafC = q.size(); // nodes present in this layer
        rem -= leafC;         // afer removing

        while (leafC--)
        {
            int leaf = q.front();
            q.pop();

            for (int nei : adj[leaf])
            {
                degree[nei]--; // Remove leaf's edge

                // if this neighbour becomes leaf
                if (degree[nei] == 1)
                    q.push(nei);
            }
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};

    vector<int> ans = findMinHeightTrees(4, edges);
    for (auto &an : ans)
        cout << an << " ";

    cout << endl;

    return 0;
}