#include<bits/stdc++.h>
#define ll long long
using namespace std;

int climbStairs(int n, vector<int>& costs)
{
   //costs[i] = cost of ith step


   //from i we can only jump to i+1,i+2, or i+3
    //dp[i] = min cost to reach step i
   vector<ll>dp(n+1,LLONG_MAX);
   dp[0]=0;

//    3: 

//    0->3
//    1->3   dp[1]+ (1-0)^2
//    2->3   which one would be the min?? : dp[2] + (3-2)^2

   for(int i = 1;i<=n;i++)
   {
       for(int j = 1;j<=3;j++)
       {
            if(i-j >= 0)dp[i] = min(dp[i],dp[i-j]+j*j + costs[i-1]);
       } 
   }
   return dp[n];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>costs = {1,2,3,4};
    cout<<climbStairs(4,costs)<<endl;

    return 0;
}