#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long countFP(vector<int>& nums,int lower, int upper)
{
    sort(nums.begin(), nums.end());

    long long count = 0;

    for(int i = 0; i <nums.size(); i++)
    {
        int l = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();

        int r = upper_bound(nums.begin() +i+i, nums.end(), upper - nums[i]) - nums.begin();

        count += (r-l);
    }

    return count;
}

/*

Time limit exceeded :(

long long countFP(vector<int>& nums,int lower, int upper)
{
    //for a pair to be fair: 0 <= i < j < n
    //And : lower <= nums[i] + nums[j] <= upper

    int count = 0;

    
    for(int i = 0; i<nums.size()-1; i++)
    {
        for(int j = i+1; j<nums.size();j++)
        {
            int sum = nums[i] + nums[j];
            if(lower <= sum && sum <= upper)
            {      
                count++;

            }
        }
    }
    return count;
}
*/


int main()
{

    vector<int>nums = {0,1,7,4,4,5};
    int lower = 3, upper = 6;

    long long ans = countFP(nums,lower,upper);

    cout<<ans<<endl;

    return 0;
}