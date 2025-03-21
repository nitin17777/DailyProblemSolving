#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>nums,vector<vector<int>>&ans,int index)
{

    //base case
    if(index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int j = index; j<nums.size(); j++)
    {
        swap(nums[index],nums[j]);
        
        //backtrack
        solve(nums,ans,index+1);

    }

}

vector<vector<int>>permute(vector<int>&nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums,ans,index);
    return ans;

}

int main()

{

    vector<int>arr = {1,2,3,4};

    vector<vector<int>>ans = permute(arr);

    for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j];

    }

    cout<<" ";

    
}






    return 0;
    
}