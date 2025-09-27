#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int triangleNumber(vector<int> &nums)
{
    // return the number fo triplets chosen from the array that can make triangles if we take them as side lengths of a triangle

    // so triplets such that : a+b> c && b+c > a && a+c >b
    int n = nums.size();
    int count = 0;

    sort(nums.begin(), nums.end());

    for (int k = n - 1; k >= 2; k--)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] > nums[k])
            {
                count += (j - i); // because all elemnts in between this i and j will satisfy this condition
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {2, 2, 3, 4};

    cout << triangleNumber(nums) << endl;

    return 0;
}