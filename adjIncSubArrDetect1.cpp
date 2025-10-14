#include <iostream>
#include <vector>
using namespace std;

bool isInc(vector<int> &nums, int start, int end)
{
    for (int i = start + 1; i < end; i++)
    {
        if (nums[i] <= nums[i - 1])
            return false;
    }
    return true;
}

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    // determine if there exists two adj subarrays of length k such that both subarrays are strcitly increasing

    // just keep pushing arrays of k size into arr1 and arr2 until all elments are utilised
    int n = nums.size();
    if (n < 2 * k)
        return false;

    for (int i = 0; i + 2 * k <= n; i++)
    {
        bool firstInc = isInc(nums, i, i + k);
        bool secInc = isInc(nums, i + k, i + 2 * k);

        if (firstInc && secInc)
            return true;
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    cout << (hasIncreasingSubarrays(nums, 3) ? "True" : " False") << endl;

    return 0;
}