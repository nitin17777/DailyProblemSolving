#include<iostream>
#include<vector>
using namespace std;

/*
        Top Down Method


        int fib(int n , vector<int>& dp)
{
    //Base case :If n is 0 or 1 , return n
    if(n <= 1)
    return n;


    //step 3:
    if(dp[n] != -1)
    {
        return dp[n];
    }


    //Step 2: 
    dp[n] = fib(n-1,dp) + fib(n-2,dp); // store result in dp[n] i.e memoise it
    return dp[n];

}
*/

//Tabulation Method
int fib(int n)
{

    vector<int>dp(n+1);

    dp[0] =0;
    dp[1] = 1;

    for(int i =2;i<=n;i++)
    {
        dp[i] = dp[i-1] +dp[i-2];
    }
    return dp[n];

}


int main()
{
    int n = 10;
     
    vector<int> dp(n+1);

    //Step 1: 
    for(int i = 0;i<=n; i++)//putting -1 initially in all cells of dp array
    {
        dp[i] = -1;
    }

    cout<<fib(n)<<endl;


    return 0;
    
}

