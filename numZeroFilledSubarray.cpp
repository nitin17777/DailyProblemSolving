#include<iostream>
#include<vector>
using namespace std;
#define ll long long

ll zeroFilledSubarray(vector<int>& nums)
{
    int n = nums.size();
    //return the subarrays filled with 0s only


    //consCount the number of zeroes,and add the number of consecutive zeroes to count
   ll consCount  = 0;
   ll ans=0;
   int i = 0;
    //calculate the occurence of each set of zeroes
    for(int i =0 ;i<n;i++)
    {
        if(nums[i]==0)
        {
            consCount++;
            ans+=consCount;
            
        }
        else
        {
            consCount = 0;
        }
    }
    return ans;
}



int main()
{
    vector<int>nums = {1,3,0,0,2,0,0,4}; // {0,0}, {0} 4 times

    long long ans = zeroFilledSubarray(nums);
    cout<<ans<<endl;

    return 0;
    
}
