#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
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