#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int countSquares(vector<vector<int>>& matrix) 
{

    int m = matrix.size();
    int n = matrix[0].size();

    // dp[i][j] will store the size of the largest square that ends at cell (i, j).


    vector<vector<int>>dp(m,vector<int>(n,0)); // making a 2d dp array of size m each of which is an array of size initiallised with 0
    
    int total = 0;

    for(int i = 0 ; i < m ;i++)
    {
        for(int j = 0; j<n; j++)
        {

            //only working with cells where 1 is present
            if(matrix[i][j] ==1)
            {
                //Base case: First row or first column
                //only 1*1 square is possible
                if(i == 0 || j== 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 1+ min({
                        dp[i-1][j],//top
                        dp[i][j-1],//left
                        dp[i-1][j-1]//top-left-diagonal
                    });

                }
                total += dp[i][j];
            }
        }
    }

    return total;

}

int main()
{
    vector<vector<int>>matrix = {
        {0,1,1,1},{0,1,1,1},{0,1,1,1},{0,1,1,1}
    };

    cout<<countSquares(matrix)<<endl;


    return 0;
    
}
