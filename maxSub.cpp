#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxSubArray(vector<int>& nums)
{
    //Kadane's Algo
    int n=nums.size();

    int maxSum = nums[0];
    int currSum = nums[0];

    for(int i = 1;i<n;i++)
    {
        currSum = max(nums[i],currSum+nums[i]);
        maxSum = max(maxSum,currSum);
    }
    return maxSum;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(a)<<endl;

    return 0;
}