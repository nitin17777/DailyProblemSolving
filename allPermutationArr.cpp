#include<bits/stdc++.h>
using namespace std;

void generatePermutation(int index, vector<int>&nums, vector<vector<int>>& ans)
{
    //base case
    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i =index; i< nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        generatePermutation(index+1,nums, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>&nums)
{
    vector<vector<int>>ans;
    generatePermutation(0, nums, ans);

    sort(ans.begin(), ans.end());

    return ans;

}

int main()
{
    vector<int>nums = {1,2,3};

    vector<vector<int>>ans = permute(nums);


    for(auto&num : nums)
    {
        for(auto& nu: num)
        {
            cout<<nu<<" ";
        }
    }
    cout<<endl;

    return 0;

}