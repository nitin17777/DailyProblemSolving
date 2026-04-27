#include<bits/stdc++.h>
#define ll long long
using namespace std;


//this checks : if we will move from A to B , can we come back from B to A??
bool isValid(vector<vector<pair<int,int>>>&dir,int type1,int type2,int dx,int dy)
{
    //type1 -> current cell type
    //type 2 -> next cell type

    //dx,dy -> directions we are moving

    for(auto& p:dir[type2])
    {
        if(p.first == -dx && p.second == -dy)return true;
    }
    return false;
}

void dfs(vector<vector<int>>&g,vector<vector<bool>>&vis,vector<vector<pair<int,int>>>&dir,int i,int j)
{
    int m = g.size(),n = g[0].size();

    //Marked the cell visited first
    vis[i][j] = true;

    //now check which is the valid path among them 
    for(auto & x:dir[g[i][j]])
    {
        int na = i+x.first, nb = j+x.second;

        if(na>=0 && nb >= 0 && na<m && nb<n && !vis[na][nb])
        {
            if(isValid(dir,g[i][j],g[na][nb],x.first,x.second))
            {
                dfs(g,vis,dir,na,nb);
            }   
        }
    }
}


bool hasValidPath(vector<vector<int>>& g)
{
    int m = g.size(),n= g[0].size();


    /*

    we will start from upper left (0,0)and we have to reach (m-1,n-1)

    Return true if any valid path exists 
    */

    vector<vector<bool>>vis(m,vector<bool>(n,false));

    //Connecting 2 cells 
    vector<vector<pair<int,int>>>dir(7);
    dir[1] = {{0,-1},{0,1}};
    dir[2] = {{-1,0},{1,0}};
    dir[3] = {{0,-1},{1,0}};
    dir[4] = {{0,1},{1,0}};
    dir[5] = {{0,-1},{-1,0}};
    dir[6] = {{0,1},{-1,0}};

    dfs(g,vis,dir,0,0);
    
    return vis[m-1][n-1];

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{2,4,3},{6,5,2}};


    cout<<(hasValidPath(g)?"True":"False")<<endl;

    return 0;
}