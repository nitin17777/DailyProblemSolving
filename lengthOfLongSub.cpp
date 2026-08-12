#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k)
{
    int n = nums.size();

    //Array is good if frequencyu of each element <= k
    //Return the length of longest good sub of nums

    unordered_map<int,int>freq;
    int left=0,ans=0;

    for(int right = 0;right<n;right++)
    {
        freq[nums[right]]++;

        while(freq[nums[right]] > k)
        {
            freq[nums[left]]--;
            left++;
        }
        ans = max(ans,right-left+1);
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,2,3,1,2,3,1,2};
    cout<<maxSubarrayLength(nums,2)<<endl;

    return 0;
}