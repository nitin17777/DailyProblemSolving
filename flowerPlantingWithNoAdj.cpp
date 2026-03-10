#include<bits/stdc++.h>
using namespace std;

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
{
    //Return ans such that ans[i]  is the type of flower planted in (i+1)th garden

    vector<vector<int>>adj(n);
    
    for(auto &p : paths)
    {
        //converting to 0 based indexing
        int u = p[0]-1;
        int v = p[1]-1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>ans(n,0);
    for(int i =0;i<n;i++)
    {
        //Tracking used flowers by neighbours

        bool used[5] = {false};

        ///checking all neighbours of garden i 
        for(auto neigh: adj[i])
        {
            //If flower is already used, mark it as unavailable now
            if(ans[neigh] != 0)
            {
                used[ans[neigh]] = true;
            }
        }

        for(int flower = 1;flower<=4;flower++)
        {
            if(!used[flower])
            {
                ans[i] = flower;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<int>>paths = {{1,2},{2,3},{3,1}};
    vector<int>ans = gardenNoAdj(3,paths);

    for(auto &x:ans)cout<<x<<" ";

    cout<<endl;      

    return 0;
}