#include<bits/stdc++.h>
#define ll long long
using namespace std;

int longestValidParentheses(string s)
{
    int n = s.size();

    if(s.empty())return 0;

    vector<int>dp(n,0);

    //We have to find the length of longest valid parantheses

    //This type of string will become invalid if ')' > '('

    //dp[i] = length of longest valid parentheses substring ending at index i
    
    int ans = 0;

    for(int i = 1;i<n;i++)
    {
        if(s[i] == ')')
        {
            
            //Case 1 : '()'
            if(s[i-1] == '(')
            {
                dp[i]=2;
                
                if(i>=2)dp[i]+=dp[i-2];
            }

            //Case 2 : "(....)"

            else
            {
                int j = i-dp[i-1]-1;
                
                if(j>=0 && s[j]=='(')
                {
                    dp[i] = dp[i-1]+2;

                    if(j>=1)dp[i] += dp[j-1];
                }
            }
            ans = max(ans,dp[i]);
        }
    }
    return ans;
}



      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cout<<longestValidParentheses(")()())")<<endl;

    return 0;
}