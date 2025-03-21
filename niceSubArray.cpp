#include<iostream>
#include<vector>

using namespace std;


int longestNiceSubarray(vector<int>& nums)
{
    int left = 0 , bitmask = 0, maxLength = 1;
    int n = nums.size();


    for(int i = 0; i<n; i++)
    {

        while((bitmask & nums[i]) != 0)
        {
            bitmask ^= nums[left];
            left ++;
        }

        bitmask |= nums[i];

        maxLength = max(maxLength,i - left +1);        
    }
    return maxLength;
}


int main()
{
    vector<int> nums = {3,1,5,11,13};

    int ans = longestNiceSubarray(nums);

    cout<<ans<<endl;


    return 0;

}