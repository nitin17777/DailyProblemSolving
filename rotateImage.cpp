#include<bits/stdc++.h>
#define ll long long
using namespace std;

void rotate(vector<vector<int>>& mat)
{
    int n = mat.size();

    // Rotate the mat 90 degree without using another matrix

    //Simply swap the a(i,j) with a(j,i),and reverse each row

    for(int i = 0;i<n;i++)
    {
        for(int j = i;j<n;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }

    for(int i=0;i<n;i++)
    {
        reverse(mat[i].begin(),mat[i].end());
    }
}
     
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>mat = {{1,2,3},{4,5,6},{7,8,9}};

    rotate(mat);

    for(auto& row:mat)
    {
        for(auto& x:row)cout<<x<<" ";

        cout<<endl;
    }

    return 0;
}
