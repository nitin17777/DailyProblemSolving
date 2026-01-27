#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int minCost(int n, vector<vector<int>> &edges)
{

    /*

    edges[i] = [ui, vi, wi] ->Directed from ui to vi with cost = wi

    At node, we may reverse the nnode and cost becomes 2*previousCost

    Return the min total cost to tecael form node 0 to node n-1
    */

    // Building adjacency list
    vector<vector<pair<int, int>>> out(n), in(n);
    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        out[u].push_back({v, w});
        in[v].push_back({u, w});
    }

    /*
     dist[u][s] = minimum cost to reach node u
                  where s = 0 means switch at u not used yet,
                   s = 1 means switch at u already used
   */
    vector<vector<ll>> dist(n, vector<ll>(2, INF));

    priority_queue<tuple<ll, int, int>,
                   vector<tuple<ll, int, int>>,
                   greater<>>
        pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty())
    {
        auto [currCost, u, used] = pq.top();
        pq.pop();

        if (currCost > dist[u][used])
            continue;

        /// Not using any switch for now
        for (auto [v, w] : out[u])
        {
            ll newCost = currCost + w;
            if (newCost < dist[v][used])
            {
                dist[v][used] = newCost;
                pq.push({newCost, v, 0});
            }
        }

        if (used == 0)
        {
            for (auto [v, w] : in[u])
            {
                ll newCost = currCost + 2LL * w;
                if (newCost < dist[v][1])
                {
                    dist[v][1] = newCost;
                    pq.push({newCost, v, 0});
                }
            }
        }
    }

    ll ans = min(dist[n - 1][0], dist[n - 1][1]);
    return (ans == INF ? -1 : ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int, int>> e = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};

    cout << minCost(4, e) << endl;

    return 0;
}