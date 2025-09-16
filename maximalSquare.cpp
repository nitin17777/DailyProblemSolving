#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix)
{
    //find the largest square containing only 1 and return the area
    int m = matrix.size();
    int n = matrix[0].size();

    int maxSide=0;

    vector<vector<int>>dp(m,vector<int>(n,0));

    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            //only dealing with cells filled with '1'
            if(matrix[i][j] == '1')
            {
                //base case : first row or first column
                if(i == 0 || j ==0)
                dp[i][j] = 1;

                else
                {
                    dp[i][j] = 1 +
                    min({dp[i-1][j],
                    dp[i][j-1],dp[i-1][j-1]
               });
                }

                maxSide = max(maxSide,dp[i][j]);
            }
        }
    }

    return maxSide*maxSide;
}

int main()
{
    vector<vector<char>>matrix = {
        {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}
    };

    cout<<maximalSquare(matrix)<<endl;
    return 0;
    
}
