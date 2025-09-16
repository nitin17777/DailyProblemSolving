#include<iostream>
#include<vector>

using namespace std;


void backtrack(int index, vector<int>&nums,vector<int>&current,vector<vector<int>>&result)
{
    result.push_back(current);

    for(int i = index ; i <nums.size();i++)
    {
        current.push_back(nums[i]);
        backtrack(i+1, nums,current,result);

        current.pop_back();
    }
}


vector<vector<int>> subsets(vector<int>& nums)
{
    //we have to return all possible subsets of given array including empty set
    vector<vector<int>>result;
    vector<int>current;
    backtrack(0,nums,current,result);

    return result;
}

int main()
{

    vector<int>nums = {1,2,3};
    vector<vector<int>>ans = susbets(nums);

    for(auto&an : ans)
    {
        for(auto a:an)
        {
            cout<<a<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;  
}
