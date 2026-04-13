#include<bits/stdc++.h>
#define ll long long
using namespace std;

int getMinDistance(vector<int>& nums, int target, int start)
{
    int n = nums.size();

    //find any i such that nums[i] == target and abs(i-start) is minimised

    //Return abs(i-start)

    int ans = INT_MAX;

    for(int i = 0;i<n;i++)
    {
        if(nums[i] == target)
        {
            ans = min(ans,abs(i-start));
            if(ans == 0)return 0;
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,2,3,4,5};
    cout<<getMinDistance(nums,5,3)<<endl;

    return 0;
}
