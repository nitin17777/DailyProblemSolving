#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //we have to return the quadruple which sums up to the given target

        int n=nums.size();
        vector<vector<int>>result;

        if(n<4)
        {
            return result;
 
        }
        sort(nums.begin(),nums.end()); //sorting given array first


        for(int i = 0;i<n-3;i++)
        {
            for(int j =1;j<n-2;j++)
            {
                int left = j+1, right = n-1;


                while(left<right)
                {
                    long long sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];

                    if(sum == target)
                    {
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});

                        left++;
                        right--;

                    }
                    else if(sum<target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;

                    }
                }
            }
        }
        return result;

        
    }


    int main()
    {

        vector<int>arr = {1,2,3,-2,-3,4};
        int tr=0;


        vector<vector<int>>answer = fourSum(arr,tr);

        for (auto& quad : answer) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}