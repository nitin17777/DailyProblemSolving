#include<bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{

    int n = graph.size();


    //graph[i] is an array adjacent to node i: There is an edge from node i to each node in graph[i]


    //Terminal Node : If there are no outgoing edges

    //Safe node : If every possible path starting from that node leads to a terminal node or nodes which cannot reach the cycle


    //So We just have to find all the nodes that are part of cycle and eliminate them 


    //Return the array containing all the safe nodes of the graph 

    //revGraph : Stores reversed edges
    vector<vector<int>>revGraph(n);

    //No. of outgoing edges from node i, if outdegree becomes 0, node becomes safe

    vector<int>outdegree(n,0);

    //Building reverse graph and computing outdegree
    for(int i = 0;i<n;i++)
    {
        outdegree[i] = graph[i].size();

        for(int v : graph[i])
        {
            //Storing reverse edge
            revGraph[v].push_back(i);
        }
    }


    //Queue to store all the safe nodes and initially all the terminal nodes are safe
    queue<int>q;
    for(int i =0;i<n;i++)
    {
        if(outdegree[i] ==0)q.push(i);
    }

    vector<int>safeNodes;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        //It is a safe node
        safeNodes.push_back(node);

        //Checking all nodes that point to this node in the original graph
        for(int parent: revGraph[node])
        {
            outdegree[parent]--;
        
            if(outdegree[parent] == 0)q.push(parent);
        }
    }

    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    vector<vector<int>>g = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int>ans = eventualSafeNodes(g);
    for(auto& x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}