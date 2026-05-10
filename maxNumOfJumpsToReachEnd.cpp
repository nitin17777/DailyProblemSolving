#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maximumJumps(vector<int>& nums, int target)
{
    int n = nums.size();

    /*

    Jump such that nums[j] - nums[i] lies bw{-target, target}

    Return the max number of jumps to reach the end index n-1
    */

    vector<int>dp(n,-1);

    //dp[i] = number of jumps possible till i
    dp[0] = 0;

    for(int i =0;i<n;i++)
    {
        if(dp[i] == -1)continue;
        for(int j = i+1;j<n;j++)
        {
            if(abs(nums[j] - nums[i]) <= target)
            {
                dp[j] = max(dp[j],dp[i]+1);
            }
        }
    }
    return dp[n-1];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   vector<int>nums = {1,3,6,4,1,2};
   cout<<maximumJumps(nums,2)<<endl;

    return 0;
}




