#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int> &nums)
{
    // return the min diff bw largest and smallest element after at most 3 moves
    int n = nums.size();
    if (n <= 4)
        return 0; // we will make 3 numbers equal to the any one of the number

    sort(nums.begin(), nums.end());

    /*
    Now we have 4 choices: change 3 largest elements
                         : change 2 largest 1 smallest
                         : change 1 largest 2 smallest
                         : change 3 smallest
    And answer would be min of these differences
    */

    int ans = INT_MAX;

    ans = min(ans, nums[n - 4] - nums[0]); // remove 3 largest
    ans = min(ans, nums[n - 3] - nums[1]); // remove 2 largest +1 smallest
    ans = min(ans, nums[n - 2] - nums[2]); // remove 1 largest + 2 smallest
    ans = min(ans, nums[n - 1] - nums[3]); // remove 3 smallest

    return ans;
}

int main()
{
    vector<int> nums = {5, 3, 2, 4};
    cout << minDifference(nums) << endl;
    return 0;
}
