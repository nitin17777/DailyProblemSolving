
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int N,int R,int M,vector<vector<int>>edges,int Q,vector<vector<int>>queries)
{
    vector<vector<pair<int,int>>>adj(N);

    for(auto &edge :edges)
    {
        int a = edge[0];
        int b = edge[1];
        int k = edge[2];

        adj[a].push_back({b,k});
        adj[b].push_back({a,k});
    }

    int ans = 0;
    for(auto&q:queries)
    {
        int i = q[1];
        int j = q[2];
        int k = q[3];

        if(q[0] == 1)
        {
            for(auto&edge:adj[i])
            {
                if(edge.first == j)
                {
                    ans+=edge.second;
                    break;
                }
            }
        }
        else
        {
            for(auto&edge: adj[i])
            {
                if(edge.first == j)
                {
                    edge.second = k;
                    break;
                }
            }

            for(auto&edge : adj[j])
            {
                if(edge.first == i)
                {
                    edge.second = k;
                    break;
                }
            }
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>edges =  {{0, 1, 5},{1, 2, 8},{0, 2, 10}};

    vector<vector<int>>queries = {
    {1, 0, 1, 0},
    {1, 1, 2, 0}
};

    cout<<solve(3,0,3,edges,2,queries)<<endl;

    return 0;
}