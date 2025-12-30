#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    // Return the shortest continuous subarray such that sorting that part would result in sorted array

    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[i + 1])
            cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {2, 6, 4, 8, 10, 9, 15}; // 5

    cout << findUnsortedSubarray(nums) << endl;

    return 0;
}