#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findUnsortedSubarray(vector<int>& nums)
{
    int n=nums.size();

    //Return the shortest continuous subarray : If we sort this subarray whole array will be sorted 


    if(is_sorted(nums.begin(),nums.end()))return 0;

    vector<int>sorted = nums;

    sort(sorted.begin(),sorted.end());

    int left = 0;
    for(int i =0;i<n;i++)
    {
        if(sorted[i] != nums[i])
        {
            left = i;
            break;
        }
    }

    int right = 0;
    for(int i =n-1;i>=0;i--)
    {
        if(sorted[i] != nums[i])
        {
            right = i;
            break;
        }
    }

    return right-left+1;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {2,6,4,8,10,9,15};
    cout<<findUnsortedSubarray(nums)<<endl;

    return 0;
}