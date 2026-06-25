#include<bits/stdc++.h>
#define ll long long
using namespace std;

int countMajoritySubarrays(vector<int>& nums, int target)
{
    int n = nums.size();


    //Majority element ->Element that appears strictly more than half of the times in that subarray


    // number of subarrays where target is the majority element

    int ans=0;

    for(int i = 0;i<n;i++)
    {
        int targetCnt = 0;

        for(int j = i;j<n;j++)
        {
            if(nums[j] == target)targetCnt++;

            int len = j-i+1;
            if(2*targetCnt > len)ans++;
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}