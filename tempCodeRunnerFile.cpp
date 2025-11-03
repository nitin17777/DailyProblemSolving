#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target)
{
    int l = 0,r = nums.size()-1;

    while(l<=r)
    {
        int mid = l+ (r-l)/2;

        if(nums[mid] == target)return true;

        //When we are unable to determine the sorted part:Simply shrink
        if(nums[l] == nums[mid] && nums[mid] == nums[r])
        {
            l++;
            r--;
        }

        //left half sorted
        else if(nums[l] <= nums[mid])
        {
            if(nums[l] <= target && target < nums[mid])
            {
                r = mid-1;
            }
            else l = mid+1;
        }

        else
        {
            if(nums[mid] < target && target <=nums[r])
            {
                l = mid+1;
            }
            else
            {
                r = mid - 1;

            }
        }
    }
    return false;
    

}

int main()
{
    vector<int>nums = {2,5,6,0,0,1,2};
    cout<<(search(nums,0) ? "true" : "false");

    return 0;
    
}
