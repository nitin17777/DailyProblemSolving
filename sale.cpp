#include <bits/stdc++.h>

using namespace std;

int money(int m, vector<int> &cost)
{
    sort(cost.begin(), cost.end());

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (cost[i] <= 0)
            ans += cost[i];
    }
    return -ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << money(m, cost) << endl;
}