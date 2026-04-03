#include<bits/stdc++.h>
using namespace std;

int maximumAmount(vector<vector<int>>& coins)
{
    int m = coins.size(),n= coins[0].size();

    //Robot can neutralise robbers in at most 2 cells

    // Return the max profit that the robot can gain


//     0 1 -1
//     1 -2 3
//     2 -3 4


    //dp[i][j][k] = max coins we can have reaching (i,j) using k neutralisations
    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));


    //Base case
    dp[0][0][0] = coins[0][0];
    
    if(coins[0][0] <0)
    {
        dp[0][0][1] = 0;//Neturalising at the first step in case we encounter negative at first
    }
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            for(int k =0;k<=2;k++)
            {
                if(i == 0 && j == 0)continue;

                int best = INT_MIN;

                //from top
                if(i>0 && dp[i-1][j][k] != INT_MIN)
                {
                    best = max(best,dp[i-1][j][k] + coins[i][j]);
                }

                //from left
                if(j>0 && dp[i][j-1][k] != INT_MIN)
                {
                    best = max(best,dp[i][j-1][k] + coins[i][j]);
                }

                dp[i][j][k] = best;

                if(coins[i][j] < 0 && k >0)
                {
                    int bestNatural = INT_MIN;

                    //from top
                    if(i > 0 && dp[i-1][j][k-1] != INT_MIN)
                    {
                        bestNatural = max(bestNatural,dp[i-1][j][k-1]);
                    }

                    //from left
                    if(j > 0 && dp[i][j-1][k-1] != INT_MIN)
                    {
                        bestNatural = max(bestNatural,dp[i][j-1][k-1]);
                    }

                    dp[i][j][k] = max(dp[i][j][k] , bestNatural);
                }
            }
        }
    }

    return max({dp[m-1][n-1][0] , dp[m-1][n-1][1], dp[m-1][n-1][2]});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>a = {{0,1,-1},{1,-2,3},{2,-3,4}};
    cout<<maximumAmount(a)<<endl;

    return 0;
}