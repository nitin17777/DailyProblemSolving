#include<bits/stdc++.h>
#define ll long long
using namespace std;



bool findSafeWalk(vector<vector<int>>& g, int health)
{
    int m = g.size(),n=g[0].size();

    //Determine if we can reach the end with health being above or equal to 1

    //go through all the paths and determine if any path can help us reach there

    deque<pair<int,int>>dq;

    vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

    //dist[r][c] = Min health lost to reach the cell r,c
    dist[0][0] = g[0][0];

    dq.push_back({0,0});

    int dr[] = {1,-1,0,0};
    int dc[] = {0,0,1,-1};

    while(!dq.empty())
    {
        auto[r,c] = dq.front();
        dq.pop_front();

        //Explorig all neighbours
        for(int k =0;k<4;k++)
        {
            int nr = r+dr[k];
            int nc = c+dc[k];

            if(nr<0 || nc<0 || nr>=m || nc >= n)continue;

            //Cost of entering this neighbour
            int cost = g[nr][nc];

            int newCost = dist[r][c] + cost;

            if(newCost < dist[nr][nc])
            {
                dist[nr][nc] = newCost;

                //Process immediately if moving costs 0
                if(cost == 0)dq.push_front({nr,nc});
                else dq.push_back({nr,nc});
            }
        }
    }
    return dist[m-1][n-1] <= health-1;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout<<(findSafeWalk(g,1)?"True":"False")<<'\n';

    return 0;
}