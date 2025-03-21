#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

    vector<vector<int>> threeSum(vector<int>& nums) {

        //return all the possible triplets of that array which makes upto the sum of 0

        int n = nums.size();
        sort(nums.begin(),nums.end());


        vector<vector<int>> result;  //initiallising  a 2d array to store result


        for(int i = 0; i<n-2; i++)
        {
            if(i > 0 && nums[i] = nums[i-1])
            {
                continue;

            }

            int target = -nums[i];
            int left = i+1;

            int right = n-1;


            while(left<right)
            {
                int sum = nums[left] + nums[right];

                if(sum == target )
                {
                    result.push_back({nums[i] , nums[left],nums[right]})
                }
            }
        }

    }


int main()
{
    return 0;

}