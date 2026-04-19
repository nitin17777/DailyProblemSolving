#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canFinish(int n, vector<vector<int>>& pre)
{

    // pre[i] = [ai,bi] -> Indicates that we must take course bi if we want to take course ai


    //Return true if we can finish all courses

    //This problem can be simplified by checking if the cycle is formed or not



    // Doing it using topological sort

    vector<vector<int>>adj(n);
    vector<int>indegree(n,0);

    //Building graph now
    for(auto& p:pre)
    {
        int a = p[0];
        int b = p[1];

        adj[b].push_back(a); //b->a == must take b before a
        indegree[a]++;
    }

    //queue for nodes with indegree 0 == courses with no pre
    queue<int>q;
    for(int i = 0;i<n;i++)
    {
        if(indegree[i] == 0)q.push(i);
    }

    int cnt = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cnt++;

        for(auto nbr:adj[node])
        {
            indegree[nbr]--;

            //If all the pre for this nbr are completed -> Add this to queue for completion count
            if(indegree[nbr] == 0)q.push(nbr);
        }
    }

    return cnt == n;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>pre = {{1,0}, {0,1}};

    cout<<(canFinish(2,pre)?"True":"False")<<endl;

    return 0;
}