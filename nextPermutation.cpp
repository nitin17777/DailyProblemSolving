#include<bits/stdc++.h>
using namespace std;

vector<int> nextPer(vector<int>&nums)
{
    int n = nums.size();

    int i = n-2;
    

    while(i >= 0 && nums[i] >= nums[i+1])
    {
        i--;
    }
    //so here i would be such that nums[i] is not greater than equal to nums[i+1]

    if(i >= 0)
    {
        int j = n-1;
        while(nums[j] <= nums[i])
        {
            j--;            
        }
        swap(nums[i],nums[j]);
    }

    reverse(nums.begin()+i +1,nums.end());
    return nums;

}


int main()
{
    vector<int>nums = {1,2,3};

    vector<int>ans =nextPer(nums);


    for(auto num: ans)
    {
        cout<<num<<" ";
        
    }
    cout<<endl;
    return 0;

}