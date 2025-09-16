#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define all(x) (x).begin() ,(x).end()

vector<vector<int>>res;

void backtrack(vector<int>& nums,vector<int>&path,vector<bool>&used)
{

    //when all the permutations are found
    if(path.size() == nums.size())
    {
        res.push_back(path);
        return;
    }


    
    for(int i = 0; i < nums.size(); i++)
    {
        if(used[i]) // when given number is already used
        continue;
    

    //for duplicate check...if holds simply skip the number
    if(i>0 && nums[i] == nums[i-1] && !used[i-1])continue;

    //after passing all this we can select the number finally
    used[i] = true;
    path.push_back(nums[i]);


    backtrack(nums,path,used); //recursive call


    //Now backtracking 
    used[i] = false; // so that it would be available for other paths
    path.pop_back(); //remove the last number
}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    // return all possible permutation


    sort(all(nums)); // sort so that dups are adjacent

    vector<bool>used(nums.size(), false); // To track if an index is already used

    vector<int>path;  //path of current permutation

    res.clear();

    backtrack(nums,path,used);

    return res;
}


int main()
{

    vector<int>nums = {1,1,2};
    vector<vector<int>>ans = permuteUnique(nums);

    for(auto& an : ans)
    {
        for(auto & a : an)
        {
            cout<<a<<" ";
        }
    }
    cout<<endl;
    return 0;
    
}
