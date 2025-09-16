#include<iostream>
#include<vector>

using namespace std;


int maximumDifference(vector<int>& nums)
{
    int n = nums.size();
    int minVal = nums[0];
    int maxDiff = -1;

    for(int i=1; i<n;i++)
    {
        if(nums[i] > minVal)
        {
            maxDiff = max(maxDiff,nums[i] - minVal);
        }

        else
        {
            minVal = nums[i];
        }
    }
    return maxDiff;
}


        //brute force approach: o(n^2)
   /* int maximumDifference(vector<int>& nums) 
    {
        //find the max difference nums[j] - nums[i] : i<j,if no such i,j exists,rerturn -1;
        int n =nums.size();

        int maxDiff = -1;
        for(int i=0; i<n; i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(nums[i] <nums[j])
                {
                    int diff = nums[j] - nums[i];
                    maxDiff = max(diff,maxDiff);
                }
            }

        }
        return maxDiff;

    }

    */

int main()
{
    vector<int>nums = {7,1,5,4};
    int ans = maximumDifference(nums);

    cout<<ans<<endl;
    return 0;
}
