#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minMoves(vector<int>& nums, int limit)
{
    int n = nums.size();


    vector<int> diff(2 * limit + 2, 0);

    //'We can replace any number from numswith any integer bw 1 and limit

    //Array will be complementary if nums[i] + nums[n-i-1] is same for all indices i


    //Return min number of moves to make nums complementary


    //Each pair would need : 0,1 or 2 changes


    //Count number of pairs with same sum

    for(int i = 0;i<n/2;i++)
    {
        int a = nums[i];
        int b = nums[n-i-1];

        int low = min(a, b) + 1;
        int high = max(a, b) + limit;
        int sum = a + b;

        diff[2] += 2;
        diff[low] -= 1;

        diff[sum]-=1;
        diff[sum+1]+=1;

        diff[high+1] += 1;

    }

    // Store minimum answer
    int ans = INT_MAX;

    // Current accumulated moves
    int moves = 0;

    /*
        Prefix sum on difference array.

        moves = total moves needed
        for target sum = s
    */

    for(int s = 2; s <= 2 * limit; s++)
    {
        moves += diff[s];

        // Keep minimum moves among all sums
        ans = min(ans, moves);
    }

    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,2,3,4};
    cout<<minMoves(nums,4)<<endl;


    return 0;
}