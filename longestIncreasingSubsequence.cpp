#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lenghtOfLIS(vector<int>& nums)
{
    //return the length of longest strictly increasing subsequence
    int n = nums.size();
    if(n == 0)return 0;

    vector<int>dp(n,1);
    int count = 1;


    for(int i=1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        count = max(count,dp[i]);
    }
    return count;
}

int main()
{

    vector<int>nums = {10,9,2,5,3,7,101,18};
    cout<<lenghtOfLIS(nums)<<endl;

    return 0;
    
}
