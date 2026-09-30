#include<bits/stdc++.h>
#define ll long long
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dung)
{
    int m=dung.size(),n=dung[0].size();

    /*

    At any point, if health drops below 0 ->Immediately dies

    Return min initial health so that he can rescue the princess

    */

    // dp[i][j] = health consumed till now to reach (i,j)
    vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));

    //since 1 health is needed after reaching the princess
    dp[m][n-1]=1;
    dp[m-1][n]=1;

    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            int need = min(dp[i+1][j],dp[i][j+1]);

            dp[i][j]=max(1, need-dung[i][j]);
        }
    }
    return dp[0][0];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>d = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout<<calculateMinimumHP(d)<<endl;

    return 0;
}