#include<bits/stdc++.h>
#define ll long long
using namespace std;

int m,n;

void dfs(vector<vector<char>>& b,int i,int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n || b[i][j] != 'O')return;

    b[i][j] = '#';

    dfs(b, i + 1, j);
    dfs(b, i - 1, j);
    dfs(b, i, j + 1);
    dfs(b, i, j - 1);
}

void solve(vector<vector<char>>& b)
{

    if(b.empty())return;

    m = b.size(),n=b[0].size();


    //first and last column
    for(int i = 0;i<m;i++)
    {
        if(b[i][0] == 'O')dfs(b,i,0);

        if(b[i][n-1] == 'O')dfs(b,i,n-1);
    }

    //first and last row
    for(int i = 0;i<n;i++)
    {
        if(b[0][i] == 'O')dfs(b,0,i);

        if(b[m-1][i] == 'O')dfs(b,m-1,i);
    }


    // Convert surrounded O's to X and restore marked O's
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(b[i][j] == 'O')b[i][j] = 'X';

            else if(b[i][j] == '#')b[i][j] = 'O';
        }
    }
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>>b = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

    solve(b);

    for(auto& row:b)
    {
        for(auto& x:row)cout<<x<<' ';

        cout<<endl;
    }
    cout<<endl;
    return 0;
}