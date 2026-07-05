#include<bits/stdc++.h>
#define ll long long
using namespace std;

int ans = INT_MAX;

void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis)
{
    //Mark the node as visited
    vis[node] = 1;

    for(auto [nxt,wt]: adj[node])
    {
        ans = min(ans,wt);

        if(!vis[nxt])dfs(nxt,adj,vis);
    }
}

int minScore(int n, vector<vector<int>>& roads)
{

    //r[i] = [ai,bi,ci] -> indicates the bidirectional road bw ai and bi with distance ci

    //score of path = min distance of any road that is coming in that path

    //Find min possible score of path bw cities 1 and n

    vector<vector<pair<int,int>>>adj(n+1);


    //making adjacency list
    for(auto& r:roads)
    {
        adj[r[0]].push_back({r[1],r[2]});
        adj[r[1]].push_back({r[0],r[2]});
    }

    vector<int>vis(n+1,0);
    dfs(1,adj,vis);

    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> r=  {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    cout<<minScore(4,r)<<'\n';


    return 0;
}