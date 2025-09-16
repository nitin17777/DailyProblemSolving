#include<bits/stdc++.h>
using namespace std;


long long maxVal(vector<int>&nums)
{
    int n = nums.size();


    //i < j < k
    //and : (nums[i] - nums[j])* nums[k] should be maximum
long long anss = 0;
long long maxAns = LLONG_MIN;


    for(int i = 0; i<n-2;i++ )
    {
        for(int j = i+1; j < n-1 ; j++)
        {
            for(int k = j +1; k < n;k++)
            {
               anss = (nums[i] - nums[j]) * nums[k];

               if(maxAns <= anss)
               {
                maxAns = anss;   
                }

            }
        }
    }

    return maxAns;
}



int main()
{

    vector<int>nums = {12,6,1,2,7};

    long long ans = maxVal(nums);

    cout<< ans <<endl;

    return 0;

}