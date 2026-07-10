#include<bits/stdc++.h>
#define ll long long
using namespace std;

// void bfs(int n,vector<vector<int>>&adj,int u ,int v,vector<int>&ans)
// {
//     queue<int>q;

//     vector<int>dist(n,-1);
    
//     dist[u] = 0;
//     q.push(u);

//     while(!q.empty())
//     {
//         int node = q.front();
//         q.pop();

//         if(node == v)
//         {
//             ans.push_back(dist[node]);
//             return;
//         }

//         for(int nxt:adj[node])
//         {
//             if(dist[nxt] == -1)
//             {
//                 dist[nxt] = dist[node]+1;
//                 q.push(nxt);
//             }
//         }
//     }
//     ans.push_back(-1);
// }

// //  NOT OPTIMAL FOR BIGGER CONSTRAINTS, CORRECT THOUGH :)
// vector<int> pathExistenceQueries1(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
// {
//     //For each query[i] = ui,vi -> Find min distance bw ui and vi , if no path exists -> return -1

//     //make full graph, and simply find distance , and add edge wherever required

//     vector<vector<int>>adj(n);

//     for(int i =0;i<n;i++)
//     {
//         for(int j = i+1;j<n;j++)
//         {
//             if(i!=j)
//             {
//                 if(abs(nums[i]-nums[j]) <= maxDiff)
//                 {
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }  
//         }
//     }
//     vector<int>ans;
//     for(auto& q:queries)
//     {
//         int u = q[0],v = q[1];

//         bfs(n,adj,u,v,ans);
//     }
//     return ans;
// }


vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
{
    vector<pair<int,int>>a;

    for(int i = 0; i < n;i++)
    {
        a.push_back({nums[i],i});
    }
    sort(a.begin(),a.end());



    //Position in the sorted array
    vector<int>pos(n);
    for(int i = 0; i < n ; i++)pos[a[i].second] = i;


    vector<int>comps(n);
    int id = 0;
    comps[0] = 0;

    for(int i =1;i<n;i++)
    {
        if(a[i].first - a[i-1].first > maxDiff)id++;
        
        comps[i] = id;
    }


    //nxt[i] = farthest reachable sorted index in one edge from i
    vector<int>nxt(n);

    int j = 0;

    for(int i = 0;i<n;i++)
    {
        while(j+1< n && a[j+1].first - a[i].first <= maxDiff)j++;

        nxt[i] = j;
    }


    //Binary lifting part:
    //up[k][i] = position reached after making 2^k greedy jumps



    int LOG = 20;


    //up[k][i] = Position reached after making 2^i greedy jumps

    vector<vector<int>>up(LOG,vector<int>(n));

    for(int i=0;i<n;i++)up[0][i] = nxt[i];


    for(int k = 1;k<LOG;k++)
    {
        for(int i = 0;i<n;i++)
        {
            up[k][i] = up[k-1][up[k-1][i]];
        }
    }


    vector<int>ans;

    for(auto&q:queries)
    {
        int u = pos[q[0]];
        int v = pos[q[1]];


        if(u==v)
        {
            ans.push_back(0);
            continue;
        }


        if(u>v)swap(u,v);

        if(comps[u]!=comps[v])
        {
            ans.push_back(-1);
            continue;
        }

        int curr = u;
        int dist = 0;

        for(int k = LOG -1;k>=0;k--)
        {
            if(up[k][curr] < v)
            {
                curr=  up[k][curr];
                dist+=(1<<k);
            }
        }
        ans.push_back(dist+1);
    }
    return ans;
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<int>nums = {1,8,3,4,2};

    vector<vector<int>>q = {{0,3},{2,4}};
    vector<int>ans = pathExistenceQueries(5,nums,3,q);

    for(auto x:ans)cout<<x<<" ";

    cout<<endl;
    
    return 0;
}