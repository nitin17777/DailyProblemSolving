#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    /*
    Return the subset such that it satisfies:
    Every pair of elements satisfy"
    ans[i] % ans[j] == 0
    OR ans[j] % ans[i] == 0

    Such that element in every pair in it are divisible by each other

    Return any of the valid solution
    */

    int n = nums.size();
    if (n == 0)
        return {};

    sort(nums.begin(), nums.end());

    // dp[i] = length of largest divisible subet that ends at index i
    vector<int> dp(n, 1);

    // previous index int the subset chain
    vector<int> parent(n, -1);

    int maxLen = 1;
    int lastIdx = 0;

    // Building dp

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0)
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }

        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            lastIdx = i;
        }
    }

    vector<int> ans;

    while (lastIdx != -1)
    {
        ans.push_back(nums[lastIdx]);
        lastIdx = parent[lastIdx];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {1, 2, 3};
    vector<int> ans = largestDivisibleSubset(nums);

    for (auto &an : ans)
        cout << an << " ";

    cout << endl;

    return 0;
}