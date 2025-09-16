#include<iostream> // For input/output
#include<unordered_map> // For hash-based map
#include<queue> // For queue used in BFS
#include<set> // To avoid duplicate neighbors (adjacency list)
#include<list> // For storing neighbors in BFS traversal
#include<vector> // For using vectors
using namespace std;

// Function to prepare adjacency list from the edge list
void prepareAdjList(unordered_map<int, set<int>>& adjList, vector<pair<int , int>> edges)
{
    for(int i = 0; i < edges.size(); i++)  // Traverse all edges
    {
        int u = edges[i].first;  // Get first node
        int v = edges[i].second; // Get second node

        adjList[u].insert(v); // Add v to u’s neighbor list
        adjList[v].insert(u); // Add u to v’s neighbor list (undirected graph)
    }
}

// BFS traversal from a given node
void bfs(unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node)
{
    queue<int> q; // Queue for BFS
    q.push(node); // Start from the given node
    visited[node] = true; // Mark node as visited

    while(!q.empty()) // Loop until queue is empty
    {
        int frontNode = q.front(); // Get front node from queue
        q.pop(); // Remove it from queue

        ans.push_back(frontNode); // Add node to result

        for(auto neighbor : adjList[frontNode]) // Traverse all unvisited neighbors
        {
            if(!visited[neighbor]) // If neighbor not visited
            {
                q.push(neighbor); // Add to queue
                visited[neighbor] = true; // Mark as visited
            }
        }
    }
}

// Function to return BFS traversal of the graph
vector<int> BFS(int vertex, vector<pair<int,int>> edges)
{
    unordered_map<int, set<int>> adjList; // Adjacency list using set for ordered & unique neighbors
    vector<int> ans; // Stores BFS traversal result
    unordered_map<int, bool> visited; // Tracks visited nodes

    prepareAdjList(adjList, edges); // Build the adjacency list from edges

    // Handle disconnected components
    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i]) // If node not yet visited
        {
            bfs(adjList, visited, ans, i); // Call BFS for that component
        }
    }

    return ans; // Return complete BFS traversal
}

int main() {
    // Edge list of the graph
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}
    };

    // Perform BFS on 5 vertices (0 to 4)
    vector<int> result = BFS(5, edges);

    // Print the BFS traversal result
    for(int node : result) {
        cout << node << " ";
    }

    return 0;
}
