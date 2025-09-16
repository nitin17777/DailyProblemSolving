#include<iostream>
#include<vector>
using namespace std;


vector<int> maxSubsequence(vector<int>& nums, int k)
{
    //we have to find the subsequence of length k with largest sum


    //Step 1 : We need to pair every number with it's index

    vector<pair<int,int>>numWithIndex;

    for(int i = 0; i <nums.size(); i++)
    {
        numWithIndex.push_back({nums[i], i});
    }

    //
}

int main()
{

    vector<int>nums = {2,1,3,3};
    int k = 2; 

    vector<int> ans = maxSubsequence(nums,k);

    for(auto & an : ans)
    {
        cout<<an<<" ";

    }
    cout<<endl;

    return 0;
    
}
