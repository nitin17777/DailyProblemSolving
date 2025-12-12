#include<bits/stdc++.h>
using namespace std;
#define ll long long

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    //Return the number of contiguous subarrays that have product of subarray less than k

    if(k<=1)return 0;


    ll cnt = 0;

    int n = nums.size();

    int left = 0;
    ll product = 1;

    for(int right = 0;right<n;right++)
    {
        product*=nums[right];

        while(product >=k && left <= right)
        {
            product/=nums[left];
            left++;
        }
        cnt += (right-left+1);
    }
    return cnt;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {10,5,2,6};
    cout<<numSubarrayProductLessThanK(nums,100)<<endl;
    
    return 0;
    
}