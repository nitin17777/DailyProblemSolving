#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    int minPathSum(vector<vector<int>>& grid) 
    {
        //we are given a grid, we have to find a path from top left to bottom right such that it minimises the sum of numbers along it's path

        int m=grid.size();
        int n = grid[0].size();

        int ans = grid[0][0]; //top left element always

        //now we have two ways : either right or down


        //Creating a dp table of same size as that of grid
        vector<vector<int>>dp(m,vector<int>(n,0));

        dp[0][0] =grid[0][0]; //Base case:AT the starting

        //Fill the first row
        for(int j = 1;j<n;j++)
        {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        //Fill in the first column
        for(int i = 1;i<m;i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        //Now filling the remaining table
        for(int i = 1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }

int main()
{
    vector<vector<int>>grid = {
        {1,2,3},{4,5,6}
    };

    int sum = minPathSum(grid);

    cout<<sum<<endl;


    return 0;

}