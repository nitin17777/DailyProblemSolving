#include<bits/stdc++.h>
#define ll long long
using namespace std;

int combinationSum4(vector<int>& nums, int target)
{
    //Return the possible combos from given array that adds up to the target

    //dp[i] = number of ways to form sum i 


    if (target <0)return 0;
    else if(target == 0)return 1;

    //because we are not sure that intermediate values crosses even long long or not
    vector<__int128>dp(target+1,0);

    dp[0] = 1;

    for(int i=1;i<=target;i++)
    {
        for(int num:nums)
        {
            if(num<=i)
            {
                dp[i] = dp[i]+dp[i-num];
            }
        }
    }
    return (int)dp[target];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,2,3};
    cout<<combinationSum4(nums,4)<<endl;

    return 0;
}