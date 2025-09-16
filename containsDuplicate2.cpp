#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    int n = nums.size();
    //return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k
    unordered_set<int>window;

    for(int i = 0;i<nums.size();i++)
    {
        //1st check for repeated ocurence
        if(window.count(nums[i]))
        {
            return true;  
        }
        //else add that number in our set
        window.insert(nums[i]);

        if(window.size() > k)
        {
            window.erase(nums[i-k]);

        }
    }

    return false;

}

int main()
{
    vector<int>nums = {1,2,3,1,2,3};
    int k = 2;

    cout<<(containsNearbyDuplicate(nums,k) ? "true" : "false");
    return 0;
    
}

