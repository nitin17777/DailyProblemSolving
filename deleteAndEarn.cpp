#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int> &nums)
{

    //Pick any nums[i], delete it to earn a[i] points, but also delete a[i] -1 and a[i]+1 from the array

    if(nums.empty())return 0;
    int maxVal = *max_element(nums.begin(),nums.end());

    // total[i] = Sum of all occurences of in nums
    vector<int>total(maxVal+1,0);
    for(int num : nums)
    {
        total[num] += num;
    }


    //prev2 = dp[i-2] == best till i-2 , prev1 = dp[i-1] == best till i-1
    int prev2 = 0,prev1 = 0;

    for(int i = 0;i<=maxVal;i++)
    {

        //Take value i 
        // if we take i , we can't take i-1 then
        int take = prev2+total[i];


        //Skip current value i, so just carry forward previous result
        int skip = prev1;

    
        int curr = max(take,skip);

        //Shifting dp states now
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nm = {3, 4, 2};
    cout << deleteAndEarn(nm) << endl;

    return 0;
}