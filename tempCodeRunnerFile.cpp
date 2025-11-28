#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dfs(int curr,int parent, vector<vector<int>>&adj,vector<int>&values,int k, int &comps)
{// DFS function returns:
    // The sum of the current subtree modulo k (or 0 if this subtree becomes a valid component).
    //
    // Arguments:
    // u = current node
    // parent = parent of u (to avoid going back)
    // adj = adjacency list of the tree
    // values = node values
    // k = divisor
    // components = reference to counter of valid connected components4



    //starting subtree with value of current node
    ll sum = values[curr];


    //Exploring all neighbors
    for(int v : adj[curr])
    {
        if(v == parent)continue;// Avoiding to revisit the parent


        ll childSum = dfs(v,curr,adj,values,k,comps);

        sum += childSum;
    }

    if(sum%k == 0)
    {
        comps++;
    
        return 0;//Returning 0 to parent as this subtree is now separated and parent shouldn't add it's value


    }
    return sum;//Otherwise return the whole uncut subtree sum upwards
}


int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
{

    //edges[i] = [ai,bi] => Indicates the edge between a and b in the tree

    //value[i] = value associated to that node


    //a valid split is obatined by removing any set of edges such that resulting comps all have values that are divisible by k, where value of connected comp is the sum of values of it's node

    //Return the max number fo comps in any valid split

    vector<vector<int>>adj(n);
    for(auto e:edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    int comps = 0;


    dfs(0,-1,adj,values,k,comps);
    return comps;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>edges = {{0,2},{1,2},{1,3},{2,4}};
    vector<int>val = {1,8,1,4,4};
    cout<<maxKDivisibleComponents(5,edges,val,6)<<endl;






    return 0;
    
}