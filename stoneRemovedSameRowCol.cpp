#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> parent;

int find(int x) // To find root of a node with path compression
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unite(int x, int y) // To connect two nodes
{
    int px = find(x);
    int py = find(y);

    // Merge if they are in different component

    if (px != py)
        parent[px] = py;
}

int removeStones(vector<vector<int>> &stones)
{
    // Each coordinate may have at most one stone

    // Stone can be removed if it shares same row or col as another stone that has not been removed

    int n = stones.size();

    // return the largest possible number of stones that can be removed

    // in the end, only coordinates with unique (x,y) will survive

    const int OFFSET = 100001;

    for (auto &stone : stones)
    {
        int row = stone[0];
        int col = stone[1] + OFFSET;

        // If not in DSU, initilise row and col
        if (parent.find(row) == parent.end())
            parent[row] = row;

        if (parent.find(col) == parent.end())
            parent[col] = col;

        unite(row, col);
    }

    unordered_set<int> comps;

    for (auto &stone : stones)
    {
        int root = find(stone[0]);
        comps.insert(root);
    }

    // Since we have to leave only one stone in one comp:
    // max removable = totalStones - number of comps
    return stones.size() - comps.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};

    cout << removeStones(stones) << endl;

    return 0;
}