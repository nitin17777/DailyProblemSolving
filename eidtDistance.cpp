#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minDistance(string word1, string word2)
{
    //find min steps to convert word1 into word2
    //we can isnert a character ,delete a character and replace a character


    int n = word1.size(),  m = word2.size();

    vector<vector<int>>dp(n+1, vector<int>(m+1 , 0));

//Base case : If word2 is empty, delete all chars from word1
    for(int i=0;i<=n;i++) dp[i][0] = i;

//If word1 is empty insert all chars of word2
    for(int j=0;j<=m;j++) dp[0][j] = j;


    for(int i = 1;i <=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            //When characters are same, no operations are needed
            if(word1[i-1] == word2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }

            else
            {
                int deleteOp = dp[i-1][j] + 1;

                int insertOp = dp[i][j-1] +1;
                
                int replaceOp = dp[i-1][j-1] +1;

                dp[i][j] = min({deleteOp,insertOp,replaceOp});
            }
        }
    }


return dp[n][m];

}

int main()
{

    string word1 = "horse";
    string word2 = "ros";

    int ans = minDistance(word1,word2);

    cout<<ans<<endl;

    return 0;

}