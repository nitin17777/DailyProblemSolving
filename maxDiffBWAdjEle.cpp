#include<iostream>
#include<vector>
using namespace std;

  int maxAdjacentDistance(vector<int>& nums)
  {
    //we are given a circular array, we have to find the max absolute difference between adjacent elements
    int diff = abs(nums[0] - nums[nums.size()-1]);

    for(int i = 0 ; i<nums.size()-1; i++)
    {
        int adjDiff = abs(nums[i] - nums[i+1]);
        diff = max(diff, adjDiff);
    }
    return diff;
  }

int main()
{

    vector<int>nums = {1,2,4};
    int ans = maxAdjacentDistance(nums); // ans = 3


    cout<< ans <<endl;

    return 0;

}