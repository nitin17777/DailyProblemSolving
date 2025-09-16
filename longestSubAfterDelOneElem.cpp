#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int longestSubarray(vector<int>& nums)
{

//delete one element such that we will get the longest subarray which consists only of '1'

//find the longest subarray which consists of only 1 zero 
int zeroCount = 0,left =0,longest = 0;

//Maintaining a sliding window where only 1 zero is present

for(int right = 0;right<nums.size();right++)
{
    if(nums[right] == 0)
    zeroCount++;

    while(zeroCount > 1)
    {
        if(nums[left] == 0)
        zeroCount--;
        left++;
    }
    longest = max(longest, right - left);
}
return longest;
}

int main()
{
    vector<int>nums = {0,1,1,1,0,1,1,0,1};
    cout<<longestSubarray(nums)<<endl;
    
    return 0;
    
}
