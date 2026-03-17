#include<bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
{
    // e[i] = fromi, toi, wi

    //return the city with smallest number of cities that are reachable through some path and distnace is atmost disThreshold

    const int INF = 1e9;


    //Matrix to store shortest distance bw cities
    vector<vector<int>>dist(n,vector<int>(n,INF));


    //Distance from a city to itself is always 0
    for(int i=0;i<n;i++)dist[i][i] = 0;

    //Filling intitial distance using given edges
    //And since graph is bidirectional, updating both the directions
    for(auto &e: edges)
    {
        int u = e[0],v = e[1],w = e[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    //Computing shortest path bw every pair of cities
    
    //k = intermediate city through which path may pass
    for(int k = 0;k<n;k++)
    {
        //i = starting day
        for(int i = 0;i<n;i++)
        {
            //j = destination city
            for(int j = 0;j<n;j++)
            {
                if(dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

                }
            }
        }
    }

    //Finding city with smallest number of reachabe cities
    int minCount = INT_MAX;
    int ans = -1;

    for(int i = 0;i<n;i++)
    {
        //Number of cities reachable from city i
        int count = 0;
        for(int j = 0;j<n;j++)
        {
            if(i != j && dist[i][j] <= distanceThreshold)count++;
        }

        if(count<=minCount)
        {
            minCount = count;
            ans = i;

        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};

    cout<<findTheCity(4,edges,4)<<endl;

    return 0;
}