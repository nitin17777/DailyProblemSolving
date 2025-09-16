#include<iostream>
#include<vector>
using namespace std;


vector<int> getRow(int rowIndex) 
{
    //Return the required row of the  pascal triangle
    
    vector<vector<int>>dp(rowIndex+1);

    for(int i = 0;i<=rowIndex;i++)
    {
        dp[i].resize(i+1,1);

        for(int j = 1;j<i;j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }

        return dp[rowIndex];//returning our required row
    }   
}


int main()
{
    vector<int>ans = getRow(3);
    for(auto&an:ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;

}

   