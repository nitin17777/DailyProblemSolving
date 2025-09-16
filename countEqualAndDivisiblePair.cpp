#include<iostream>
#include<vector>
using namespace std;

int countPairs(vector<int>& nums , int k)
{
    int n = nums.size();
    //we have to return the number of pairs such that nums[i] == nums[j] && (i*j) %k ==0

    int count = 0;

    for(int i = 0; i<n; i++)
    {
    
        for(int j = n-1; j>=0; j--)
        {
            if(nums[i] == nums[j] && ((i*j)/ k == 0))
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int>nums = {3,1,2,2,2,1,3};
    int k = 2;

    int ans = countPairs(nums,k);

    cout<<ans<<endl;

    return 0;
}