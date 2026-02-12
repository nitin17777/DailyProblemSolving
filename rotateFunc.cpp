#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxRotateFunction(vector<int> &nums)
{
    int n = nums.size();

    // Return the max value of F(0) + F(1)+....

    ll sum = 0;
    ll F = 0;

    // Computing sum and F(0)
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        F += 1LL * i * nums[i];
    }

    ll ans = F;
    // Now computing each F(k) using recurence relation
    for (int k = 1; k < n; k++)
    {
        F = F + sum - 1LL * n * nums[n - k];
        ans = max(ans, F);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {4, 3, 2, 6};
    cout << maxRotateFunction(nums) << endl;

    return 0;
}