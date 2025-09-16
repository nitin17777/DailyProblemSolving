#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9+7;



int climb(int n)
{

  if(n<=0)return 0; 
  if(n ==1)return 1;
  if(n ==1)return 1;



  vector<int>dp(n+1);

  dp[1] = 1;
  dp[2] = 2;

  for(int i =3;i<=n;i++)
  {
    dp[i] = dp[i-1] + dp[i-2];

  }

  return dp[n];
}

/*
int climb(int n)
{
      //Suppose we are given a number. We need to find the number of ways to reach this sum using only 1s and 2s
      if(n == 0 || n==1)
      return 1;

      int prev2 = 1,prev1= 1, current = 0;

      //iterating from 2 to n
      for(int i = 2; i <= n; i++)
      {
        current = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = current;
      }
      return current;
}
      */

int main()
{

    int ans = climb(4);

    cout<<ans<<endl;

}