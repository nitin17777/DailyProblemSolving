#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int V = 7;

bool dfs(int s, int t, vector<int>& parent, vector<vector<int>>& cap, vector<bool>& vis)
{
    vis[s] = true;

    if(s == t) return true;

    for(int v = 0; v < V; v++)
    {
        if(!vis[v] && cap[s][v] > 0)
        {
            parent[v] = s;
            if(dfs(v, t, parent, cap, vis))
                return true;
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>> cap, int source, int sink)
{
    vector<int> parent(V);
    int maxFlow = 0;
    int pathCount = 1;

    while(true)
    {
        vector<bool> vis(V,false);
        fill(parent.begin(), parent.end(), -1);

        if(!dfs(source, sink, parent, cap, vis))
            break;

        int flow = INT_MAX;

        for(int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            flow = min(flow, cap[u][v]);
        }

        cout << "Path " << pathCount++ << " : ";

        for(int v = sink; v != -1; v = parent[v])
            cout << v;

        cout << endl;
        cout << "Maximum flow in this path = " << flow << endl;

        for(int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            cap[u][v] -= flow;
            cap[v][u] += flow;
        }

        maxFlow += flow;
    }

    return maxFlow;
}