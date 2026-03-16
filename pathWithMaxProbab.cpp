#include<bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
{
    // edges[a,b] =  undirected graph connecting nodes  a and b with probability of success of traversing that edge succProb[i]

    //Find the path with max probability of success to go from start to end and return the success probability, if there is not path from start to end , return 0

    //Find all paths form s to e , go on computing probability and return the highest possible one


    //Makign adjaceny list

    //Probability of traversing that edge  = succProb[i]

    vector<vector<pair<int,double>>>adj(n);

    for(int i = 0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        double p = succProb[i];

        adj[u].push_back({v,p});
        adj[v].push_back({u,p});
    }

    //best[i] = max probability to reach i
    vector<double>best(n,0.0);
    best[start] = 1.0;

    priority_queue<pair<double,int>>pq; // {prob,node}
    pq.push({1.0,start});

    while(!pq.empty())
    {
        auto [prob,u] = pq.top();
        pq.pop();

        //Early exit if we reach the target
        if(u == end)return prob;

        //Skip in case of outdated entry
        if(prob < best[u])continue;

        //Relax neighbours

        for(auto &[v,p] : adj[u])
        {
            double newProb = prob*p;

            if(newProb > best[v])
            {
                best[v] = newProb;
                pq.push({newProb,v});
            }
        }
    }
    return 0.0;//Case of no path
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>e = {{0,1},{1,2},{0,2}};

    vector<double>suc = {0.5,0.5,0.2};

    cout<<maxProbability(3,e,suc,0,2)<<endl;

    return 0;
}