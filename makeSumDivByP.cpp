#include <bits/stdc++.h>
using namespace std;

int minSubarray(vector<int> &nums, int p)
{

    /*
    //we have to remove the smallest subarray such that sum of remaining elements is divisible by P
    int n = nums.size();

    int summ = accumulate(nums.begin(),nums.end(),0);

    if(summ % p == 0)return 0;


    vector<int>temp = nums;
    sort(temp.begin(),temp.end());

    //when smallest part to be removed is of size 1
    for(int i = 0; i < n ; i++)
    {
        if((sum - nums[i]) % p == 0)return 1;
    }


    vector<int>prefix(n);
    prefix[0] = nums[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + a[i];
    }

    unordered_map<int,int>rems;
    for(auto& cc : pref)
    {
        int remainder = cc %p;
        rems[cc] = remainder;
    }
*/

    // total sum = 16 => 16 % 9 = 7= >so we need to remove minimum of 7 such that this 7 comes from some continuous and possibly the smallest part of the array

    //(6,6), (9,0), (14,5), (16,7)

    /* This sliding window technique won't work
    int n = nums.size();


    int summ = accumulate(nums.begin(),nums.end(),0);

    int req = summ % p;

    int left = 0, sum = 0,ans = INT_MAX;

    for(int right = 0;right < n; right++)
    {
        sum += nums[right];

        while(sum >= req)
        {
            ans = min(ans,right-left+1);
            sum-=nums[left];
            left++;
        }
    }
    return(ans == INT_MAX ? -1 : ans);

    */
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {6, 3, 5, 2};
    cout << minSubarray(nums, 6) << endl;

    return 0;
}