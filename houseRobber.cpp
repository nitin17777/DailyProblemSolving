#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    vector<int> dp(n);

    dp[0] = nums[0];

    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}

/*
int rob(vector<int>&nums)
{
    int n = nums.size();

    vector<int>sum(n);

    //start from 0th and 1st index leaving every adjacent element, return the greater one

    int sum1= 0;
    for(int i = 0;i <nums.size();i+=2)
    {
        sum1+=nums[i];
    }


    int sum2= 0;
    for(int i = 1;i <nums.size();i+=2)
    {
        sum2+=nums[i];
    }

    return max(sum1,sum2);
}
    */

int main()
{
    vector<int> nums = {2, 1, 1, 2};
    cout << rob(nums) << endl;

    return 0;
}
