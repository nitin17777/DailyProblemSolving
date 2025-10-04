#include <bits/stdc++.h>
using namespace std;

long long maxCakes(int n, vector<int> &cakes, int m)
{
    // ith oven bakes ai cakes every second and ckae remains in their respective ovens until they are collected

    // at end of each second she may teleport to any oven inc the one she is currently at and collect all the cakes that have acccumulated in that ovenn upto that point

    // return the max number of cakes maple can collect in m seconds

    // sorting in descending order
    sort(cakes.begin(), cakes.end(), greater<int>());

    // we can visit at most min(m,n)ovens

    int ovensToVisit = min(m, n);

    long long totalCakes = 0;

    for (int i = 0; i < ovensToVisit; i++)
    {
        long long time = m - i;
        long long cakesFromOven = (long long)cakes[i] * time;
        totalCakes += cakesFromOven;
    }
    return totalCakes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> cakes(n);
        for (int i = 0; i < n; i++)
        {
            cin >> cakes[i];
        }
        cout << maxCakes(n, cakes, m) << endl;
    }
    return 0;
}