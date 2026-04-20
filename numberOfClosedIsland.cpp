#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;

void dfs(vector<vector<int>>& g,int i ,int j)
{

    if(i<0 || j<0 || i>=n || j>=m || g[i][j] == 1)return;
    

    //marking it as visited
    g[i][j] = 1;

    dfs(g, i+1, j);
    dfs(g, i-1, j);
    dfs(g, i, j+1);
    dfs(g, i, j-1);
}


int closedIsland(vector<vector<int>>& g)
{
    n = g.size(),m= g[0].size();

    //Return the number of closed islands


    //Closed island -> island surrounded by 1 totally


    //Return the total number of closed islands

    //Removing boundary connected islands first
    
    for(int i = 0;i<n;i++)
    {
        if(g[i][0] == 0)dfs(g,i,0);
        if(g[i][m-1] == 0) dfs(g,i,m-1);
    }

    for (int j = 0; j < m; j++) 
    {    
        if (g[0][j] == 0) dfs(g, 0, j);
        if (g[n-1][j] == 0) dfs(g, n-1, j);
    }


    int cnt = 0;
    for(int i =1;i<n;i++)
    {
        for(int j = 1;j<m;j++)
        {
            if(g[i][j]==0)
            {
                dfs(g,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};

    cout<<closedIsland(g)<<endl;

    return 0;
}