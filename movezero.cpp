#include<bits/stdc++.h>
#define ll long long
using namespace std;

void moveZeroes(vector<int>& nums)
{
    int n = nums.size();

    int j = 0;
    //swap 0 with last index
    for(int i = 0;i<n;i++)
    {
        if(nums[i] != 0)
        {
            swap(nums[i],nums[j]);
            j++;
        }
    }
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {0,1,0,3,12};
    
    moveZeroes(nums);

    for(auto & x:nums)cout<<x<<" ";

    cout<<endl;


    return 0;
}