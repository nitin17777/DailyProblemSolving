#include<bits/stdc++.h>
#define ll long long
using namespace std;

string shortestCommonSupersequence(string s1, string s2) 
{
    int n = s1.size(),m=s2.size();

    //finding the common part from both the string.
    //now construct both the given strings around it


    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    //Now making lcs dp :

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else 
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }


    //Now building SCS
    int i = n,j=m;
    string ans = "";


    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans+=s1[i-1];
            i--;
            j--;
        }

        //Taking from s1 
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans+=s1[i-1];
            i--;
        }

        //Taking from s2
        else
        {
            ans+=s2[j-1];
            j--;
        }
    }

    while(i>0)ans+=s1[--i];
    while(j>0)ans+=s2[--j];

    reverse(ans.begin(),ans.end());
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<shortestCommonSupersequence("abac","cab")<<endl;
    
    return 0;
}




