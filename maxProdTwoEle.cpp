#include<bits/stdc++.h>
#define ll long long
using namespace std;


int maxProduct(vector<int>& nums)
{
    int n = nums.size();
    sort(nums.begin(),nums.end());

    return (nums[n-1]-1) *(nums[n-2]-1);
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {3,4,5,2};
    cout<<maxProduct(nums)<<endl;


    return 0;
}