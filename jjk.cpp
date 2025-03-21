#include<iostream>
#include<vector>
using namespace std;


vector<int> Sum(vector<int>&nums,int target)
{

    int n = nums.size();
    for(int i = 0; i<n ;i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if (nums[i] +nums[j] == target)
        {
            return{i,j};

        }

        }
    }
    return{};

}

int main()
    {

        vector<int>nums = {1,2,3,4,5};

        int target = 7;

        vector<int>result = Sum(nums,target);

        if(!result.empty())
        {
            cout<<"Indices: "<<result[0]<<","<<result[1]<<endl;

        }

        else
        {
            cout<<"No two given numbers add upto the target. "<<endl;

        }
        return 0;
    }