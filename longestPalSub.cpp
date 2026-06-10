#include<bits/stdc++.h>
#define ll long long
using namespace std;

int longestPalindromeSubseq(string s)
{
    int n = s.size();

    //find the length of longest palindromic subsequence

    //dp[i][j] = length of lps in s[i...j]

    vector<vector<int>>dp(n,vector<int>(n,0));

    //For single characters
    for(int i = 0;i<n;i++)dp[i][i] = 1;

    for(int len = 2;len<=n;len++)
    {
        for(int i = 0; i+len-1 < n;i++)
        {
            int j = i+len-1;

            if(s[i] == s[j])
            {

                //for base case: since no middle part in between them
                if(len == 2)dp[i][j] = 2;

                else dp[i][j] = 2 + dp[i+1][j-1];
            }
            else
            {
                //either ignore one character: left or right
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];    
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<longestPalindromeSubseq("bbbab")<<endl;

    return 0;
}