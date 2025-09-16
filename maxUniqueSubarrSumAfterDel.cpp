#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;



int maxSum(vector<int>& nums)
{
    //we need to delete the elements only when given array is not unique
    int left = 0, right = 0;
    int maxSum = 0;
    unordered_map<int,int>freq;
    int sum = 0;
    for(int right=0; right<nums.size(); right++)
    {
        while(freq[nums[right]] > 0)
        {
            sum -= nums[left];
            
            freq[nums[left]]--;
            left++;
        }

    sum += nums[right];
    freq[nums[right]]++;

    maxSum = max(sum,maxSum);
}

return maxSum;
}



int main()
{
    vector<int>nums = {-20,20};

    int ans = maxSum(nums);

    cout<<ans<<endl;

    return 0;
}