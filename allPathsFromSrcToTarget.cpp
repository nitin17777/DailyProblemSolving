#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>graph,vector<int>path,vector<vector<int>>ans)
{
    int target = graph.size()-1;

    //Store the path on reaching destinationno 
    if(node == target)
    {
        ans.push_back(path);
        return;
    }

    //Exploring all neighbours
    for(int next : graph[node])
    {
        path.push_back(next);
        dfs(next,graph,path,ans);
        path.pop_back();  //Backtrack
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{

    //Return all the possible paths from node 0 to n-1
    vector<vector<int>>ans;
    vector<int>path = {0};
    dfs(0,graph,path,ans);
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};

    vector<vector<int>> ans = allPathsSourceTarget(graph);

    for (auto &an : ans)
    {
        for (auto &a : an)
            cout << a << " ";

        cout << endl;
    }
    return 0;
}