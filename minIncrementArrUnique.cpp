#include<bits/stdc++.h>
using namespace std;

int minIncrementForUnique(vector<int>& nums)
{
    int n = nums.size();

    //In one move we can increae any number by 1

    //Return min moves to make every element of the array unique

    sort(nums.begin(),nums.end());

    int ans = 0;

    
    for(int i = 1;i<n;i++)
    {
        if(nums[i] <= nums[i-1])
        {
            int needed = nums[i-1]+1;
            ans += needed - nums[i];
            nums[i] = needed;
        }
    }    
    return ans;
    // 1 1 2 2 3 7
}   // 1 2 3 4 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<int>nums = {3,2,1,2,1,7};
    cout<<minIncrementForUnique(nums)<<endl;
    return 0;
}