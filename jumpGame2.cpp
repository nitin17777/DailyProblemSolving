#include<bits/stdc++.h>
#define ll long long
using namespace std;


        //DP APPROACH : O(n^2)

// int jump(vector<int>& nums)
// {
//     int n = nums.size();

//     // Min jumps to reach index n-1

//     //Try every jump from current index and determine the shortest one

//     int ans = 0;

//     vector<int>dp(n,INT_MAX);

//     dp[0] = 0;

//For every position i : 
    //Try every position j that i can jump to 
        //update the min jumps to reach j

//     for(int i = 0;i<n;i++)
//     {
//         for(int j = i+1;j<n && j <= i+nums[i];j++)
//         {
//             dp[j] = min(dp[j], dp[i]+1);

//         }
//     }
//     return dp[n-1];
// }


int jump(vector<int>& nums)
{
    int n = nums.size();
    int jumps = 0; 

    int currEnd = 0,farthest = 0;

    for(int i = 0;i<n-1;i++)
    {
        farthest = max(farthest,i+nums[i]);

        if(i == currEnd)
        {
            jumps++;
            currEnd = farthest;
        }
    }
    return jumps;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {2,3,1,1,4};
    cout<<jump(nums)<<endl;

    return 0;
}