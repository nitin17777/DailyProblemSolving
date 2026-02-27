#include <bits/stdc++.h>
using namespace std;

int minOperations(string s, int k)
{
    int n = s.size();

    // Select exaclty k different indices and flip each '0' to 1 and each 1 to 0

    // Return min ops to make all chars in string equal to 1 , if not possible return -1

    /*

    one operation: flip x zeroes and  k -x ones -> Net  = x - (k-x) = 2x -k

    */

    int m = 0;
    for (auto c : s)
    {
        if (c == '0')
            m++;
    }

    // dist[i] =  min ops to reach state i zeros
    vector<int> dist(n + 1, INT_MAX);

    vector<set<int>> nodeSets(2);
    // nodeSets[0]->Stores all unvisited even states

    // nodeSets[1] ->Stores all unvisited odd states

    for (int i = 0; i <= n; i++)
    {
        nodeSets[i % 2].insert(i);
    }

    queue<int> q;

    q.push(m);   // starting from initial zero count
    dist[m] = 0; // 0 ops to reach itself

    // Removing starting state from unvisited set
    nodeSets[m % 2].erase(m);

    // BFS Traversal

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        int c1 = max(k - n + curr, 0); // Lower bound of c
        int c2 = min(curr, k);         // upper bound of c

        int lnode = curr + k - 2 * c2;
        int rnode = curr + k - 2 * c1;

        auto &nodeSet = nodeSets[lnode % 2];

        // Iterating over all unvisited states in the interval [lnode,rnode]

        auto it = nodeSet.lower_bound(lnode);

        while (it != nodeSet.end() && *it <= rnode)
        {
            int nextState = *it;

            // Set distance
            dist[nextState] = dist[curr] + 1;

            q.push(nextState); // Push into bfs queue

            // Remove from unvisited set
            it = nodeSet.erase(it);
        }
    }

    // If after BFS : state = 0, return its distance

    return dist[0] == INT_MAX ? -1 : dist[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << minOperations("110", 1) << endl;

    return 0;
}