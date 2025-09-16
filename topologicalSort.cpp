#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<list>
using namespace std;


//Topologicla Sort ->Linear ordering of vertices such that for every edge u -v, u always appears before v in that ordering


void topoSort(int node, unordered_map<int,bool>&visited, stack<int>&s,unordered_map<int,list<int>>&adj)
{

    visited[node] = true; //marking current node as true


    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour]) //if neighbour is not visited simply do dfs on it 
        {
            topoSort(neighbour,visited,s,adj);
        }
    }
    //after all the neighbours are processed, push the current node into stack
    s.push(node);
}

vector<int>topologicalSort(vector<vector<int>>&edges,int n , int e)
{

    //adjacency list
    unordered_map<int,list<int>>adj;

    for(int i =0;i <e;i++)
    {
        int u  = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }


    unordered_map<int,bool>visited;
    stack<int> s;

    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            topoSort(i,visited,s,adj);
        }
    }
    vector<int>ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

}


int main()
{

    int n = 6; 
    int e=6;

    vector<vector<int>>edges =  {
        {5, 0}, {5, 2}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };
    vector<int>result = topologicalSort(edges,n,e);

    for(auto& res :result)
    {
        cout<<res<<" ";
    }
    cout<<endl;

    return 0;

}