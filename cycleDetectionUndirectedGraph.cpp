#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

bool isCyclicBFS(int src , unordered_map<int,bool>&visited, unordered_map<int,list<int>>&adj)
{
    unordered_map<int,int>parent;

    parent[src] = -1; // source node has no parent
    visited[src] = 1;//marking source as visited
    queue<int>q;
    q.push(src);

    while(q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front])
        {
            if(visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }

            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1; 

                parent[neighbour] = front;
            }
        } 
    }
    return false;   
}

bool isCyclicDFS(int node,int parent,unordered_map<int,bool>&visited, unordered_map<int, list<int>>adj)
{
    visited[node] = true;

    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
           bool cycleDetected = isCyclicDFS(neighbour,node,visited,adj);

           if(cycleDetected)
           {
            return true;
           }
           else if(neighbour != parent)
           {
            //cycle present
            return true;
           }
        }
        return false;
    }

}

string cycleDetection(vector<vector<int>>& edges,int n , int m)
{
    //create an adjaceny list
    unordered_map<int,list<int>>adj;


    for(int i = 0; i <m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components

    unordered_map<int,bool>visited;

    for(int i = 0;i <n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCyclicBFS(i,visited,adj);
            if(ans == 1)
            return "Yes";    
        }
    }
    return "No";
}

int main()
{
    vector<vector<int>>edges = {
        {1,2},{2,3},{1,3}
    };
    int n = 3,m=3;

    string ans = cycleDetection(edges,n,m);

    cout<<ans<<endl;


    return 0;

}