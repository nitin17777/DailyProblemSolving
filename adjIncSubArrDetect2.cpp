#include <iostream>
#include <vector>

using namespace std;

int maxIncreasingSubarrays(vector<int> &nums)
{
    // find the max value of k for which there exists two adj subarrays of length k such that both of them are strictly increasing

    // return the max length possible of two adj subarrays
    int n = nums.size();
    if (n < 2)
        return 0;

    vector<int> left(n, 1), right(n, 1);

    // left[i] = number of strictly increasing sequence that ends at index i

    // right[i] =  number of strictly increasing sequence that starts at index i

    // computing increasing length ending at i
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    // computing increasing length starting at i
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        ans = max(ans, min(left[i - 1], right[i])); // min because we are forced to take minimum length to match the lenght of both subarrays
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    cout << maxIncreasingSubarrays(nums) << endl;

    return 0;
}
