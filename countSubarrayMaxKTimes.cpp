#include<bits/stdc++.h>
using namespace std;


long long countSub(vector<int>&nums, int k)
{
    
    int n = nums.size();
    int maxx = *max_element(nums.begin() , nums.end());     // we have the largest element of the array rn


    //so we have to find the number of subarray such that the maximum element of subarray atleast k times


    // now we have to find all those arrays which contains that element atlese 'k' times ,and if it doesn't, return 0;

    long long ans = 0;
    int left = 0 , right = 0;
    int maxxCount = 0;

    while(right < n)
    {
        if(nums[right] == maxx)
        maxxCount++;

   while(maxxCount >= k) //all subArrays following this rule are valid
   {

    ans += (n - right); // if subarrays till right have max of 'k' elements, then subArrays which include elements after right will also contain those max 'k' elements

    if(nums[left] == maxx) maxxCount--;
    left++;
}
    right++;
   }

   return ans;
}



int main()
{
    vector<int>nums = {1,3,2,3,3};
    int k = 2;

    long long ans = countSub(nums,k);

    cout<<ans<<endl;

    return 0;
}