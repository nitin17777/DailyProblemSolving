#include<bits/stdc++.h>
#define ll long long
using namespace std;

int orangesRotting(vector<vector<int>>& g)
{
    int m = g.size(),n= g[0].size();

    /*
    
    0->empty cell 
    1->fresh orange
    2->rotten orange

    orange that is 4 directionally adjacent to rotten oranges becomes rotten 

    //Min number of mins such that no cell has any frsh orange


    We need all cells to be 2

    
    */

    //if cell is 2 -> mark all the adjacent pairs as rotten


    queue<pair<int,int>>q;
    int fresh = 0;

    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(g[i][j] == 2)q.push({i,j});
            else if(g[i][j] == 1)fresh++;
        }
    }

    int mins = 0;

    //BFS now
    vector<int>dx = {-1,1,0,0};
    vector<int>dy = {0,0,1,-1};

    while(!q.empty() && fresh>0)
    {
        int size = q.size();

        while(size--)
        {
            auto[x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && g[nx][ny]==1)
                {
                    g[nx][ny]=2;
                    fresh--;

                    q.push({nx,ny});
                }
            }
        }
        mins++;
    }
    return fresh == 0?mins:-1;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{2,1,1},{1,1,0},{0,1,1}};

    cout<<orangesRotting(g)<<endl;


    return 0;
}