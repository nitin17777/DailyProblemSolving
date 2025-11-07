#include <bits/stdc++.h>
using namespace std;

int maxSumDivThree(vector<int> &nums)
{

    vector<int> dp(3, 0);
    // dp[0] -> max sum % 3 == 0
    // dp[1] -> max sum % 3 == 1
    // dp[2] -> max sum % 3 == 2

    for (int num : nums)
    {
        vector<int> curr = dp;

        for (int r = 0; r < 3; r++)
        {
            int newSum = dp[r] + num;
            int newRem = newSum % 3;

            curr[newRem] = max(curr[newRem], newSum);
        }
        dp = curr;
    }
    return dp[0];
}

/*
int maxSumDivThree(vector<int>& nums)
{
    //max Sum divisible by 3

    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum %3 == 0)return sum;

    sort(nums.begin(),nums.end());

    int rem1a = INT_MAX,rem2b = INT_MAX;
    int rem2a = INT_MAX,rem2b=INT_MAX;


    for(int x : nums)
    {
        if(x% 3 == 1)
        {
            if(rem1a == INT_MAX)rem1a = x;

        }
    }
}
*/

int main()
{
    vector<int> nums = {3, 6, 5, 1, 8};
    cout << maxSumDivThree(nums) << endl;

    return 0;
}
