#include<iostream>
#include<string>
#define MOD 1e9+7;
#include<algorithm>
#include<vector>

using namespace std;

/* TLE
int solve(vector<int>&cost,int n)
{
    //Base Case
    if(n ==0)return cost[0];

    if(n == 1)return cost[1];


    int ans = cost[n] + min(solve(cost,n-1), solve(cost,n-2));
    return ans;

}*/

/* Method 1:

int solve(vector<int>&cost,int n,vector<int>&dp)
{
    //Base Case
    if(n ==0)return cost[0];

    if(n == 1)return cost[1];

    if(dp[n] != -1)
    {
        return dp[n];

    }


    dp[n] = cost[n] + min(solve(cost,n-1,dp), solve(cost,n-2,dp));
    return dp[n];
}
    */


    //Method 2
    int solve(vector<int>&cost,int n)
    {
        vector<int>dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2;i<n;i++)
        {
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
        
    }



int minCostClimbingStairs(vector<int>& cost)
{
    // we can start from 0th or 1st stair
    // we have to pay cost only when we can move 1 or 2 steps
    // return min cost to reach top floor

    // int n= cost.size();

    // int ans = min(solve(cost,n-1) , min(solve(cost,n-2)));

    // return ans;


    int n = cost.size();
//1   vector<int>dp(n+1, -1);

   //1 int ans = min(solve(cost,n-1,dp) , solve(cost,n-2,dp));
    //1 return ans;

    return solve(cost,n);

}

/* TLE with recursion
int solve(long long nStairs, int i)
{
    if( i==nStairs)return 1;

    if(i>nStairs)
    {
        return 0;
    }

    return (solve(nStairs,i+1) + solve(nStairs,i+2));

}


int countDistinctWaysToClimbStair(long long nStairs)
{

    int ans = solve(nStairs,0);
    
}
    */

int main()
{
    vector<int>cost = {10,15,20};


    cout<<minCostClimbingStairs(cost)<<endl;
    return 0;
    
}
