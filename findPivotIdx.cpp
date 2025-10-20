#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    // we have to calculate the pivot index of  this array

    // index where sum of all elements at left = sum of all elements at right

    // compute right and left sum for every index

    int n = nums.size();
    vector<int> left(n), right(n);

    // Left Sum
    left[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] + nums[i];
    }

    // Right sum
    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] + nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (left[i] == right[i])
            return i;
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(nums) << endl;
    return 0;
}
