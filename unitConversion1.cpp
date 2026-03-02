#include <bits/stdc++.h>
using namespace std;

vector<int> baseUnitConversions(vector<vector<int>> &conversions)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> conv = {{0, 1, 2}, {1, 2, 3}};
    vector<int> ans = baseUnitConversions(conv);
    for (auto &x : ans)
        cout << x << " ";

    cout << endl;
    return 0;
}