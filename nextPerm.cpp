#include<bits/stdc++.h>
#define ll long long
using namespace std;

void nextPermutation(vector<int>& nums)
{
    int n = nums.size();

    //We generally want to make as small change as possible in the right

    int i = n-2;

    //Finding the first decreasing position(dip) from right
    while(i>=0 && nums[i] >= nums[i+1])i--;

    //If a larger permutation exists
    if(i>=0)
    {
        int j = n-1;

        //Smallest element greater than nums[i]
        while(nums[j]<=nums[i])j--;

        swap(nums[i],nums[j]);
    }

    //Making the suffix smallest as possible
    reverse(nums.begin()+i+1,nums.end());
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,2,3};
    nextPermutation(nums);
    for(auto& x:nums)cout<<x<<" ";

    cout<<endl;

    return 0;
}

// 1 2 3 -> 1 3 2 