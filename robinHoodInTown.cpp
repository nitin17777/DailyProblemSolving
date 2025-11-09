#include <bits/stdc++.h>
using namespace std;

int minGold(vector<int> &wealth)
{
    int n = wealth.size();

    // Special case: if n <= 2, more than half can never be unhappy
    if (n <= 2)
        return -1;

    sort(wealth.begin(), wealth.end());

    // Calculate total wealth
    long long totalWealth = 0;
    for (int w : wealth)
        totalWealth += w;

    // We need strictly more than n/2 people to be unhappy
    // That means at least (n/2 + 1) people unhappy
    int requiredUnhappy = n / 2 + 1;

    // The person at index (requiredUnhappy - 1) needs to be unhappy
    // This is the "threshold" person - if they're unhappy, enough people are unhappy
    int thresholdWealth = wealth[requiredUnhappy - 1];

    // For this person to be unhappy:
    // thresholdWealth < (totalWealth + x) / (2 * n)
    // 2 * n * thresholdWealth < totalWealth + x
    // x > 2 * n * thresholdWealth - totalWealth

    long long minX = 2LL * n * thresholdWealth - totalWealth;

    // If minX is already <= 0, then Robin Hood already appears (or never will)
    if (minX < 0)
        return 0;

    return (int)minX;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> wealth(n);
        for (auto &x : wealth)
            cin >> x;

        cout << minGold(wealth) << endl;
    }
    return 0;
}