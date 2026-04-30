#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxPathScore(vector<vector<int>>& g, int k) {


        set<int>st;
        for(auto &x:g)
        {
            for(auto &y:x)
            {
                st.insert(y);
            }
        }

        if((st.size()==1) && g[0][0] == 0)return 0;

        if(g.size() == 1&& g[0].size()==1)return 0;

        int m = g.size(),n= g[0].size();

        if(k == 0)return -1;

        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        //dp[i][j][c] = max score at cell (i,j) with total cost exactly c

        int startCost = (g[0][0] == 1 || g[0][0] == 2)?1:0;

        if(startCost < k)dp[0][0][startCost] = g[0][0];

        for(int i =0 ;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                for(int c = 0;c<=k;c++)
                {
                    if(dp[i][j][c] == -1)continue;

                    //Moving right
                    if(j+1<n)
                    {
                        int cost = (g[i][j+1] == 1 || g[i][j+1] == 2)?1:0;

                        if(c+cost<=k)
                        {
                            dp[i][j+1][c+cost] = max(dp[i][j+1][c+cost], dp[i][j][c]+g[i][j+1]);
                        }
                    }


                    //Now moving down
                    if(i+1 <m)
                    {
                        int cost = (g[i+1][j] == 1 || g[i+1][j] == 2)?1:0;

                        if(cost + c <= k)
                        {
                            dp[i+1][j][c+cost] = max(dp[i+1][j][c+cost], dp[i][j][c] + g[i+1][j]);
                        } 
                    }

                }
            }
        }

        int ans = -1;
        for(int c=0;c<=k;c++)
        {
            ans = max(ans, dp[m-1][n-1][c]);
        }
        return ans;
        
    }

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{0,1},{2,0}};
    cout<<maxPathScore(g,1)<<endl;

    return 0;
}