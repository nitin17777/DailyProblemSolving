#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool dfs(vector<vector<char>>& g,vector<vector<bool>>&vis,int i, int j,int pi,int pj)
{
    int m = g.size(),n = g[0].size();

    //Marking the current cell visited now
    vis[i][j] = true;

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};

    for(int d = 0;d<4;d++)
    {
        int ni = i+dx[d];
        int nj = j+dy[d];


        if(ni >= 0 && nj>=0 && ni<m && nj <n)
        {
            if(g[ni][nj] == g[i][j])
            {
                if(!vis[ni][nj])
                {
                    //Depends on the result from next cell now
                    if(dfs(g,vis,ni,nj,i,j))return true;
                }

                //if neighbour is already visited and it is not the parent ->then we found the cycle
                else if(!(ni == pi && nj == pj))return true;
            }
        }
    }
    return false;
}


bool containsCycle(vector<vector<char>>& g)
{
    int m = g.size(),n = g[0].size();


    //Determine if there exists a cycle consisting of same value in the grid


    //maintain a visited array and incase we reach any unvisited cell return true 

    vector<vector<bool>>vis(m,vector<bool>(n));

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(!vis[i][j] )
            {
                if(dfs(g,vis,i,j,-1,-1))return true;
            }
        }
    }
    return false;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>>g = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};

    cout<<(containsCycle(g)?"True":"False")<<endl;
    
    return 0;
}