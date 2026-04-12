#include<bits/stdc++.h>
#define ll long long
using namespace std;


void dfs(int i, int j,vector<vector<char>>& g,vector<vector<bool>>&vis)
{

    int m = g.size(),n = g[0].size();

    if(i<0 || j<0 || i>=m || j>=n || g[i][j] == '0' || vis[i][j])return;

    vis[i][j] = true;

    //Checking in all directions now
    dfs(i+1,j,g,vis);
    dfs(i,j+1,g,vis);
    dfs(i-1,j,g,vis);
    dfs(i,j-1,g,vis);
}

int numIslands(vector<vector<char>>& g)
{
    int m= g.size();
    int n = g[0].size();

    //Determine the number of islands

    // Determine how many 1s are connected tor each other horizontally or vertically

    /*

    Select node -> do dfs until 0 is encountered and keep marking every node visited

    as soon as we are done with dfs for that index -> increase count by 1
     */

    vector<vector<bool>>vis(m,vector<bool>(n,false));
    int cnt =0;

    for(int i = 0;i<m;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(g[i][j] == '1' && !vis[i][j])
            {
                dfs(i,j,g,vis);
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

    int t;
    cin>>t;

    vector<vector<char>>g = {{'1','1','1','1','0'},
                    {'1','1','0','1','0'},
                    {'1','1','0','0','0'},
                    {'0','0','0','0','0'}};

    cout<<numIslands(g)<<endl;

    return 0;
}




