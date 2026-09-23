#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minOperations(vector<int>& nums, int x)
{
    int n = nums.size();
    

    //We can either remove leftmost or rightmost element from the array

    //Return min moves to convert x to exactly 0

    //Final elements that remain are always a contiguous subarray


    int total=accumulate(nums.begin(),nums.end(),0);
    int target = total-x;

    if(target == 0)return n;

    int maxLen = -1;
    int sum = 0;
    int left = 0;

    for(int right = 0;right<n;right++)
    {
        sum += nums[right];

        while(left<=right && sum>target)
        {
            sum-=nums[left];
            left++;
        }


        if(sum==target)
        {
            maxLen = max(maxLen,right-left+1);
        }
    }

    if(maxLen == -1)return -1;

    return n-maxLen;

    // while(left<=right)
    // {
    //     if(nums[left] <= nums[right])
    //     {
    //         if(x-nums[right]>=0)
    //         {
    //             x-=nums[right];
    //             right--;
    //             ans++;
    //         }

    //         else 
    //         {
    //             x-=nums[left];
    //             left++;
    //             ans++;
    //         }
            
    //     }

    //     else 
    //     {
    //         if(x-nums[left]>= 0)
    //         {
    //             x-=nums[left];
    //             left++;
    //             ans++;
    //         }
    //         else 
    //         {
    //             x-=nums[right];
    //             right--;
    //             ans++;
    //         }
    //     }
    //     if(x==0)return ans;
    // }
    // return -1;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,1,4,2,3};
    cout<<minOperations(nums,5)<<endl;

    return 0;
}