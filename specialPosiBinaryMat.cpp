#include<bits/stdc++.h>
using namespace std;

int numSpecial(vector<vector<int>>& mat)
{
    int m = mat.size();
    int n = mat[0].size();

    vector<int>col,row;

    //Row sum
    for(int i =0;i<m;i++)
    {
        int sum = 0;
        for(int j = 0;j<n;j++)
        {
            sum+=mat[i][j];
        }
        row.push_back(sum);
    }

    for(int i =0;i<n;i++)
    {
        int sum = 0;
        for(int j = 0;j<m;j++)
        {
            sum+=mat[j][i];
        }
        col.push_back(sum);
    }


    int ans=0;
    for(int i =0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if((mat[i][j] == 1) &&(row[i] ==1) && col[j] == 1)ans++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>mat = {{1,0,0},{0,0,1},{1,0,0}};
    cout<<numSpecial(mat)<<endl;

    return 0;
}