#include<iostream>
#include<vector>

using namespace std;

void backtrack(vector<int>&nums,vector<int>&path,vector<bool>&used,vector<vector<int>>&ans)
{
    if(path.size() == nums.size())
    {
        ans.push_back(path);
        return;
    }
    
    for(int i = 0;i<nums.size();i++)
    {
        if(used[i])
        continue;//we can skip the element if it is already used

        path.push_back(nums[i]);
        used[i] = true;

        backtrack(nums,path,used,ans);

        path.pop_back();
        used[i] = false;

    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    //we have to return all the possible permutations of given nums array
    vector<int>path;
    vector<vector<int>>ans;

    vector<bool>used(nums.size(), false);
    backtrack(nums,path,used,ans);

    return ans;
}

int main()
{

    vector<int>nums = {1,2,3};

    vector<vector<int>>ans = permute(nums);

    for (auto&nu: ans)
    {
        for(auto& nuu : nu)
        {
            cout<<nuu<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    return 0;
    
}