#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<vector<int>>&g,vector<bool>&vis)
{
    vis[i] = true;//marking city i as visited now
    for(int j = 0;j<g.size();j++)
    {
        if(g[i][j] == 1 && !vis[j])//if both cities are directly connected and not visited that city, then visit the city
        {
            dfs(j,g,vis);

        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected)
{

    int n = isConnected.size();
    vector<bool>vis(n,false);// To track visited cities

    int provinces = 0;

    for(int i = 0;i < n;i++)
    {
        if(!vis[i])//if city is not visited yet, it is a new province
        {
            provinces++;
            dfs(i,isConnected,vis);//now marking all cities reachable from i
        }
    }
    return provinces;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>a = {{1,1,0},{1,1,0},{0,0,1}};

    cout<<findCircleNum(a)<<endl;




    return 0;
    
}