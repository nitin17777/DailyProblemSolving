#include<iostream>
#include<vector>
#include<climits>
using namespace std;



bool increasingTriplet(vector<int>&nums)
{
    int first = INT_MAX; // in order to store the smallest number 
    int second = INT_MAX; // to store nu

    for(auto num : nums)
    {
        if(num <= first)
        {
            first = num;
        }

        else if(num <= second)
        {
            second = num;
        }
        else
        {
            return true;
        }
    }
    return false;
}
/*
bool increasingTriplet(vector<int>& nums)
{
    //return true if there exists a triplets of indices : i,j, k : i<j<k and  nums[i] < nums[j] <nums[k]

    for(int i = 2;i<nums.size();i++)
    {
        if(nums[i] > nums[i-1] &&nums[i-1] > nums[i-2])
        {
            return true;
        }
    }
    return false;
}
*/

int main()
{
    vector<int>nums = {5,4,3,2,1};

    if(increasingTriplet(nums))
    {
        cout<<"True"<<endl;
    }

    else
    cout<<"False"<<endl;



    return 0;

}