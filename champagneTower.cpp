#include<bits/stdc++.h>
using namespace std;


//More optimised approach
double champagneTower(int poured, int row, int col)
{

    vector<vector<double>>dp(102,vector<double>(102,0.0));

    dp[0][0] = poured;

    for(int i = 0;i<=row;i++)
    {
        for(int j = 0;j<=i;j++)
        {

            if(dp[i][j] > 1.0)
            {
                double of = (dp[i][j] - 1.0 )/ 2.0;

                dp[i][j] = 1.0;
                dp[i+1][j]+=of;
                dp[i+1][j+1] += of;
            }
        }
    }
    return dp[row][col];
}


/*
double champagneTower(int poured, int row, int col)
{
    /*

    Each row has n glasses

    After pouring some cups of drink, return full the jth glass in the ith row is 


    dp[i][j] = drink reaching the (i, j)th glasss


    overflow = max(0,dp[i][j] - 1)

    dp[i+1][j] = overflow/2
    dp[i+1][j+1] = overflow/2
    

    vector<vector<double>>dp(101,vector<double>(101,0.0));
    
    dp[0][0] = poured;

    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=i;j++)
        {
            double overflow = (dp[i][j] - 1.0)/2.0;

            if(overflow > 0)
            {
                dp[i+1][j] += overflow;
                dp[i+1][j+1] += overflow;
            }
        }
    }
    return min(1.0,dp[row][col]);
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<champagneTower(1,1,1)<<endl;
    return 0;
}