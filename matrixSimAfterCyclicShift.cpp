#include<bits/stdc++.h>
using namespace std;

bool areSimilar(vector<vector<int>>&mat, int k)
{
    int m = mat.size(),n=mat[0].size();

    /*
    Ops: Even indexed rows are cyclically shifted to left
         Odd indexed rows are cyclically shifted to right
    
    */

    //True if final  modified matrix after k steps is identical to original matrix
    


    k%=n;

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(mat[i][j] != mat[i][(j+k)%n])return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>mat = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<(areSimilar(mat,4)?"True":"False")<<endl;

    return 0;
}