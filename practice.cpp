#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{
    int n = adj.size();
    vis[node] = true;

    cout << node << " ";

    for (int next : adj[node])
    {
        if (!vis[next])
        {
            dfs(next, adj, vis);
        }
    }
}

void maxheapify(vector<int> &arr, int n, int i)
{
    int largest = 1;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (left < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        maxheapify(arr, n, i);
    }
}