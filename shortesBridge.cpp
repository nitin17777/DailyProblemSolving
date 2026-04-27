#include<bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(vector<vector<int>>&g,int i,int j,queue<pair<int,int>>&q)
{
    int n = g.size();

    //Boundary checks
    if(i<0 || j<0 || i>=n || j>=n || g[i][j] != 1)return;


    //Marking the cell first as part of 1st island
    g[i][j] = 2;

    //storing for bfs further
    q.push({i,j});

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for(int d = 0;d<4;d++)
    {
        dfs(g,i+dx[d],j+dy[d],q);
    }
}

int shortestBridge(vector<vector<int>>& g)
{
    int n = g.size();


    //We can convert 0 to 1 to connect 2 islands, return how many 0s we must flip to connect two islands


    // 1 1 1 1 1 
    // 1 0 0 0 1
    // 1 0 1 0 1
    // 1 0 0 0 1
    // 1 1 1 1 1

    // 0 1 0 
    // 0 0 0
    // 0 0 1

    queue<pair<int,int>>q;
    bool found = false;

    //MArking our first island
    for(int i=0;i<n && !found;i++)
    {
        for(int j = 0; j<n && !found; j++)
        {

            if(g[i][j] == 1)
            {
               dfs(g,i,j,q);
               found = true;
            }
        }
    }

    //Now BFS to reach second island
    int steps = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while(!q.empty())
    {
        int sz = q.size();

        while(sz--)
        {
            auto [x,y] = q.front();
            q.pop();


            for(int d = 0;d<4;d++)
            {
                int nx = x+dx[d];
                int ny = y + dy[d];

                if(nx<0 || ny<0 || nx>=n || ny>= n)continue;

                //reached second island
                if(g[nx][ny] == 1)return steps;

                //to avoid visiting the same cell again during bfs
                if(g[nx][ny] == 0)
                {
                    g[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
        steps++;
    }
    return -1;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<int>>g = {{0,1},{1,0}};
    cout<<shortestBridge(g)<<endl;

    return 0;
}