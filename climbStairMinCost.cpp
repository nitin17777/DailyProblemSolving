#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minCostClimbingStairs(vector<int>& a)
{
    int n = a.size();
    if (n==1)return a[0];


    //Start from 0th or 1st index
    vector<int>dp(n);

    //dp[i] = min cost to reach top from ith stair

    dp[0] = a[0];
    dp[1] = a[1];
    

    for(int i = 2;i<n;i++)
    {
        dp[i] = a[i] + min(dp[i-1],dp[i-2]);
    }

    return min(dp[n-1],dp[n-2]);
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>c = {10,15,20};
    cout<<minCostClimbingStairs(c)<<endl;

    return 0;
}