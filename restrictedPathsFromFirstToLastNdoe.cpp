#include<bits/stdc++.h>
#define ll long long
using namespace std;

static const int MOD = 1e9+7;
using pli = pair<ll,int>;

vector<vector<pair<int, int>>> adj;
vector<ll> dist;
vector<int> dp;

int dfs(int u ,int n)
{
    if(u==n)return 1;

    if(dp[u] != -1)return dp[u];

    ll ways = 0;

    for(auto [v,w]:adj[u])
    {
        if(dist[u] > dist[v])ways = (ways+dfs(v,n))%MOD;
    }
    return dp[u]=ways;
}

int countRestrictedPaths(int n, vector<vector<int>>& edges)
{
    //edge[i] = {ui,vi, weight}

    //Restricted path: distanceToLastNode(zi) > distanceToLastNode(zi+1)

    //Determine number of restricted paths from node 1 node n and mod 1e9+7


    adj.assign(n+1,{});
    dist.assign(n+1,LLONG_MAX);
    dp.assign(n+1,-1);

    for (auto& e : edges) 
    {
        int u = e[0], v = e[1], w = e[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    //dijkstra from node n

    priority_queue<pli,vector<pli>,greater<pli>>pq;

    dist[n] = 0;
    pq.push({0,n});


    while (!pq.empty()) 
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) 
        {
            if (dist[v] > d + w) 
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

        return dfs(1,n);
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   vector<vector<int>>edges = {{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};

   cout<<countRestrictedPaths(5,edges)<<'\n';

    return 0;
}