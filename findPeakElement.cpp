#include<bits/stdc++.h>
using namespace std;

int peak(vector<int>&nums)
{
    int left = 0, right = nums.size() -1;

    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] > nums[mid+1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
    }
    return left;
}

int main()
{

    vector<int>nums = {1,2,3,1};
    
    cout<<peak(nums)<<endl;

    return 0;
    
}
