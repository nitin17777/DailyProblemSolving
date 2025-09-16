#include<iostream>
#include<vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target)
{
    //we have to find the ways by adding + or - before each integer in nums to find the resultant target sum

    int total = 0;
    //Calculating total sum first
    for(int n: nums)
    total+=n;

    //checking if it is even possible to do so or not
    if((total+target)%2 != 0 || total < abs(target))
    return 0;


    // P = numbers we put a + in front of
    // N = numbers we put a - in front of


    // sum(p) + sum(n) = totalSum
    // sum(p) - sum(n) = target

    // 2(sum(p) = totalSum + target) => sum(p) = (totalSum + target )/ 2

    int subsetSum = (total + target) /2;

    //dp[i] = number of ways to get sum i
    vector<int>dp(subsetSum+1,0);
    dp[0] = 1;// since there is only one way to get sum 0 => Do nothing

    for(int num : nums)
    {
        for(int j = subsetSum; j >= num; j--)
        {
            dp[j] += dp[j -num];
        }    
    }
    return dp[subsetSum];
}

int main()
{

    vector<int>nums ={1,1,1,1,1};

    cout<<findTargetSumWays(nums,3)<<endl;

    return 0;
    
}
