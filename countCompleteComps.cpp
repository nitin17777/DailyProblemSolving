#include<bits/stdc++.h>
#define ll long long
using namespace std;


void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,int&nodes,int& edges)
{
    vis[node] = true;

    nodes++;
    edges+=adj[node].size();

    for(auto nei : adj[node])
    {
        if(!vis[nei])dfs(nei,adj,vis,nodes,edges);
    }
}

int countCompleteComponents(int n, vector<vector<int>>& edges)
{
    //We have to determine the number of connected components

    //Complete componet : There must be an edge between every pair of it's verteices

    vector<vector<int>>adj(n);
    for(auto& e:edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    int ans = 0;
    vector<bool>vis(n,false);

    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            int nodes = 0,edges = 0;

            dfs(i,adj,vis,nodes,edges);
            edges/=2;

            //BEcause in complete graph : no. of edges = n * (n-1)/2
            if(edges == nodes*(nodes-1)/2)ans++;
        }
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>e = {{0,1},{0,2},{1,2},{3,4},{3,5}};

    cout<<countCompleteComponents(6,e)<<"\n";
    return 0;
}