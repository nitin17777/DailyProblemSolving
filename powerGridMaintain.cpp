#include <bits/stdc++.h>
using namespace std;

// Optimised method using DSU(Disjoint Set Union)
vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
{
}

/*  TLE using this method
vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
//Making an adjaceny list
{
    vector<vector<int>>adj(c+1);
    for(auto & p:connections)
    {
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }

    //Tracking the online stations
    vector<bool>online(c+1,true);

    vector<int>ans;

    //Now processing each query
    for(auto&query : queries)
    {
        int type = query[0];
        int x = query[1];

        if(type == 2)//Then station goes offline
        {
            online[x]= false;
        }

        else if(type == 1)
        {
            if(online[x])ans.push_back(x);

            //Case when x station is itself offline and it will now be operated the samllest online station
            else
            {
                vector<bool>vis(c+1,false);
                queue<int>q;

                q.push(x);
                vis[x] = true;

                int smallest = INT_MAX;

                //BFS traversal of this component now
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();


                    if(online[node])
                    {
                        smallest = min(smallest,node);
                    }

                    for(int nei : adj[node])
                    {
                        if(!vis[nei])
                        {
                            vis[nei] = true;
                            q.push(nei);
                        }
                    }
                }
                if(smallest == INT_MAX)ans.push_back(-1);
                else ans.push_back(smallest);

            }
        }
    }
    return ans;
}
*/

int main()
{
    vector<vector<int>> queries = {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}};
    vector<vector<int>> connections = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

    vector<int> ans = processQueries(5, connections, queries);
    for (auto x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}
