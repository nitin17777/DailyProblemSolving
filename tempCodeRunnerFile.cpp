#include<bits/stdc++.h>
#define ll long long
using namespace std;


int largestInteger(vector<int>& nums, int k)
{
    int n = nums.size();

    //Almost missing if that number x is only present in one subarray of size k

    unordered_map<int,int>cnt;
    for(int l=0;l<=n-k;l++)
    {
        unordered_set<int>seen;

        for(int i=l;i<l+k;i++)seen.insert(nums[i]);

        for(int x:seen)cnt[x]++;
    }

    int ans = -1;
    for(auto&[x,c]:cnt)
    {
        if(c==1)ans = max(ans,x);
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {3,9,2,1,7};
    cout<<largestInteger(nums,3)<<'\n';

    return 0;
}