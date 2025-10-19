#include <bits/stdc++.h>
using namespace std;

long long maximumTotalDamage(vector<int> &power)
{
    unordered_map<int, long long> damage;

    // Step 1: accumulate total damage for each distinct power
    for (int x : power)
        damage[x] += x;

    // Step 2: sort the unique powers
    vector<int> keys;
    for (auto &p : damage)
        keys.push_back(p.first);
    sort(keys.begin(), keys.end());

    int n = keys.size();
    vector<long long> dp(n, 0);

    dp[0] = damage[keys[0]];

    for (int i = 1; i < n; i++)
    {
        long long take = damage[keys[i]];
        int j = i - 1;

        // find the last index that doesn’t conflict (diff > 2)
        while (j >= 0 && keys[i] - keys[j] <= 2)
            j--;

        if (j >= 0)
            take += dp[j];

        dp[i] = max(dp[i - 1], take);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> power = {5, 9, 2, 10, 2, 7, 10, 9, 3, 8};
    cout << maximumTotalDamage(power) << endl;
    return 0;
}
