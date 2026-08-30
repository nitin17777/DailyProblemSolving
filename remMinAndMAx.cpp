#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minimumDeletions(vector<int>& nums)
{
    int n = nums.size();

    if(n<=2)return n;

    //Remove the max and min from array 

    // pair<int,int>maxi;
    // pair<int,int>mini;

    // int small=INT_MAX,big = INT_MIN;

    // int miniIdx = 0;
    // int maxiIdx = 0;

    // for(int i = 0;i<n;i++)
    // {
    //     if(nums[i] < small)
    //     {
    //         mini.first=nums[i];
    //         mini.second=i;
    //     }

    //     if(nums[i]>big)
    //     {
    //         maxi.first = nums[i];
    //         maxi.second = i;
    //     }

    //     maxiIdx = min(maxi.second, n-maxi.second);
    //     miniIdx = min(mini.second, n-mini.second);
    // }
    // return miniIdx+maxiIdx+1;


    int mx = *max_element(nums.begin(),nums.end()),mn = *min_element(nums.begin(),nums.end());

    int mxIdx=0,mnIdx=0;

    for(int i = 0 ;i<n;i++)
    {
        if(nums[i] == mx)mxIdx =i;

        if(nums[i]==mn)mnIdx = i;
    }

   
    int ans=INT_MAX;


    //Both from left
    ans =min(ans,max(mnIdx,mxIdx)+1);

    //Both from right
    ans = min(ans,n-min(mnIdx,mxIdx));

    //Min from left, max form right
    ans = min(ans,mnIdx+1 + n-mxIdx);
    
    //Max from left, min from right
    ans = min(ans,mxIdx+1+n-mnIdx);

    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums={2,10,7,5,4,1,8,6};
    cout<<minimumDeletions(nums)<<endl;

    return 0;
}