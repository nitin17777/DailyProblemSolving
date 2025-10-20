#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minStartValue(vector<int> &nums)
{
    int minPrefix = 0;
    int sum = 0;
    int n = nums.size();
    for (int num : nums)
    {
        sum += num;
        minPrefix = min(minPrefix, sum);
    }
    /*

    runningSum[i]=startValue+prefixSum[i]

    we want runningSum[i]≥1for all i

            startValue+prefixSum[i] >= 1
            startValue = 1-prefixSum[i]

            //but to satisfy this , we should have minimal prefixSum we can get
            so startValue = 1- min(prefixValues)
    */
    return 1 - minPrefix;

    // for (int i = 1; i < n; i++)
    // {
    //     prefixSum[i] = prefixSum[i - 1] + nums[i];

    //     minSum = min(prefixSum[i], minSum);
    // }
}

/*
int minStartValue(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefixSum(n);

    int start = nums[0] + 1; // getting the starting digit

    prefixSum[0] = nums[0] + start;
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];

        if (prefixSum[i] < 1)
        {
            // increase start until prefixSum is greater than equal to 1
        }
    }
    return start;
}
    */

/*
int minStartValue(vector<int>& nums)
{
    //start with any value you want

    //which start value will be such that sum at none of the step would be less than 1

    int n = nums.size();
    int negative = 0, positive =0;

    // for(int i =0 ;i <n;i++)
    // {
    //     if(nums[i] < 0)
    //     {
    //         negative +=nums[i];
    //     }
    //     else
    //     {
    //         positive+=nums[i];
    //     }
    // }

    // if(negative < positive)return 1;

    int start = nums[0]+1;


    int i = 0;
   // for(int i = start;i<100;i++)
   while(i<n)
    {
        start+=nums[i];

        if(start<1)
        start++;

        else i++;
    }
    return start;


}
*/

int main()
{
    vector<int> nums = {-3, 2, -3, 4, 2};
    cout << minStartValue(nums) << endl;

    return 0;
}
