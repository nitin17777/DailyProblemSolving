#include<bits/stdc++.h>
#define ll long long
using namespace std;

int rob(vector<int>& nums)
{
    int n = nums.size();

    //We can't rob two adjacent houses at once 

    if(n==0)return 0;
    if(n==1)return nums[1];

    vector<int>dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[1],nums[0]);

    for(int i =2;i<n;i++)
    {
        dp[i] = dp[i-2]+nums[i];
    }
    return dp[n-1];

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {1,2,3,1};
    cout<<rob(a)<<endl;

    return 0;
}