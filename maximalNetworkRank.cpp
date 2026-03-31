#include<bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& roads)
{

    //Network Rank = Number of directly connected roads to the either city


    vector<int>degree(n,0);
    set<pair<int,int>>st;


    //Making adjacency list and degree of each edge
    for(auto & r :roads)
    {
        int u = r[0];
        int v = r[1];

        degree[u]++;
        degree[v]++;

        st.insert({u,v});
        st.insert({v,u});
    }

    int maxi = 0;


    //checking all pairs now
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            int rank = degree[i] + degree[j];

            if(st.count({i,j}))
            {
                rank--;
            }
            maxi = max(maxi,rank);
        }
    }
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>r = {{0,1},{0,3},{1,2},{1,3}};
    cout<<maximalNetworkRank(4,r)<<endl;

    return 0;
}