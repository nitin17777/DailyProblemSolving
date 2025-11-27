#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &nums, int k)
{
    // max sum of subarray of nums such that size of subarray is divisible by k

    // create window of k's multiple => record the sum and move the window forward and find max sum accordingly

    int n = nums.size();

    vector<long long> pre(n + 1, 0);

    // Building prefix sum
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + nums[i];
    }

    vector<long long> best(k, LLONG_MAX);

    // Tracking min prefix sum seen so far for each index mod k
    long long ans = LLONG_MIN;

    for (int i = 0; i <= n; i++)
    {
        int mod = i % k;

        if (best[mod] != LLONG_MAX)
        {
            ans = max(ans, pre[i] - best[mod]);
        }

        // updating min prefix sum for this mod group
        best[mod] = min(best[mod], pre[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {-1, -2, -3, -4, -5};
    cout << maxSubarraySum(nums, 4) << endl;

    return 0;
}