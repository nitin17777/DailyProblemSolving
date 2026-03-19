#include<bits/stdc++.h>
using namespace std;

int numberOfSubmatrices(vector<vector<char>>& g)
{
    int n = g.size(),m = g[0].size();

    //Return the number of submatrices that contain g[0][0] + atlease one X  and equal frequency of X and Y should be there
    int cnt = 0;

    //prefix sum of values (x,y and .)
    vector<vector<int>>pref(n+1,vector<int>(m+1,0));
    vector<vector<int>>prefx(n+1,vector<int>(m+1,0));

    //Converting grid to values: x -> 1, y -> -1, . -> 0

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
           int val = 0;
           if(g[i-1][j-1] == 'X')val = 1;
           else if(g[i-1][j-1] == 'Y')val = -1;

           pref[i][j] = val + pref[i-1][j]+ pref[i][j-1] - pref[i-1][j-1];

           prefx[i][j] = (g[i-1][j-1] == 'X') + prefx[i-1][j]+prefx[i][j-1]-prefx
           [i-1][j-1];
        }
    }

    for(int i = 1; i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            int sum = pref[i][j];
            int xcount = prefx[i][j];

            if(sum == 0 && xcount > 0)cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>>g = {{'X','Y','.'},{'Y','.','.'}};
    cout<<numberOfSubmatrices(g)<<endl;
    return 0;
}