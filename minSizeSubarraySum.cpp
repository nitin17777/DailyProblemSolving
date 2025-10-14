#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    // minimal length of subarray whose sum is greater than equal to target, if no such subarray exists, simply return 0

    int n = nums.size();

    int minLen = INT_MAX;
    int sum = 0;

    // iterate over nums till target sum is achieved and then take care of that subarray with target sum

    int left = 0;

    for (int right = 0; right < n; right++)
    {
        sum += nums[right];

        while (sum >= target)
        {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}

int main()
{

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums) << endl;

    return 0;
}