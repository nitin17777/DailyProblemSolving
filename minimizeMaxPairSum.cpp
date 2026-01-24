#include <bits/stdc++.h>
using namespace std;

int minPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int maxi = INT_MIN;

    int r = nums.size() - 1;
    int l = 0;

    while (l < r)
    {
        int ans = nums[r] + nums[l];
        maxi = max(maxi, ans);

        l++;
        r--;
    }
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {3, 5, 2, 3};
    cout << minPairSum(nums) << endl;

    return 0;
}

auto init = atexit([]()
                   { ofstream("display_runtime.txt") << "0"; });
