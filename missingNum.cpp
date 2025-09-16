#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>nums)
{
 //we have to find the missing number from the given array

 int n = nums.size();
 int xall = 0;
 int xnums = 0;

 for(int i=0;i<n;i++)
 {
    xall^=i;
 }

 for(auto&num:nums)
 {
    xnums^=num;
 }

 return xall^xnums;

}

int main()
{
    vector<int>nums = {3,0,1};
    int ans = missingNumber(nums);

    cout<<ans<<endl;
    
    return 0;

}