#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

    bool isPossible(vector<int>&nums, int p, int mid)
    {
        int count = 0;
        int i =1;
        while(i < nums.size())
        {
            if(nums[i] - nums[i-1] <= mid)
            {
            count++;

            i += 2;//if condition satisfies, skip both elements for next iteration
            }

            else // just skip the current element
            i++;  
        }
        return count >= p;
    }

    
    int minimizeMax(vector<int>& nums, int p)
    {
        int n = nums.size();
        //we have to find p pair of indices such that max difference amongst all pairs is minimized also no index must not appear more than once amongs p pairs

        sort(nums.begin(), nums.end());

        int low = 0, high = nums[n-1] - nums[0], ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(isPossible(nums,p,mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            low = mid+1;


        }
        return ans;

        //we have to find the max difference among all p pairs
    }

int main()
{

    vector<int>nums = {10,1,2,7,1,3};
    int p = 2;

    int ans = minimizeMax(nums,p);

    cout<<ans<<endl;

    return 0;

}
