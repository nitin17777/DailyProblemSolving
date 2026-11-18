#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
    //flights[i] = [fromi, toii,pricei]


    //return cheapest price form src to dist with atmost k stops, else return -1

    // dist[i] = min cost to reach city i using flights processed so far

    vector<int>dist(n,INT_MAX);
    dist[src] = 0;

    for(int i = 0;i<=k;i++)
    {
        vector<int>temp = dist;

        for(auto&f:flights)
        {
            int u = f[0];
            int v = f[1];
            int price = f[2];


            //if u city is available 
            if(dist[u] != INT_MAX)temp[v] = min(temp[v],dist[u]+price);
        }
        dist=temp;
    }
    if(dist[dst] == INT_MAX)return -1;

    return dist[dst];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> f = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout<<findCheapestPrice(4,f,0,3,1)<<endl;

    return 0;
}