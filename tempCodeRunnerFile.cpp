#include<bits/stdc++.h>
using namespace std;



int largestMagicSquare(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    
    /*
    Grid filled with integrs such that every col,row,diagonal sums are equal 

    Return the side length of largest magic that can be found within this grid
    */

    vector<vector<int>>row(m,vector<int>(n+1,0));
    vector<vector<int>>col(m+1,vector<int>(n,0));


    for(int i =0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            row[i][j+1] = row[i][j] + grid[i][j];
            col[i+1][j] = col[i][j] + grid[i][j];
        }
    }

    //
    auto isMagic = [&](int r,int c,int k)
{
    //Taregt Sum -> Sum of first row of the square

    int target = row[r][c+k] - row[r][c];


    //Checking all row sums
    for(int i = r; i <r+k;i++)
    {
        int currRowSum = row[i][c+k] - row[i][c];
        if(currRowSum != target)return false;
    }


    //Checking col sums
    for (int j = c; j < c + k; j++)
    {
        int currColSum = col[r + k][j] - col[r][j];
        if (currColSum != target)return false;
    }

    //checking diagonals
    int diag1 = 0,diag2 = 0;
    for(int  i =0 ;i<k;i++)
    {
        diag1 += grid[r+i][c+i];
        diag2 += grid[r+i][c+k-i-1];
    }

    if(diag1 != target || diag2 != target)return false;
    

    return true;
};


for(int k = min(m,n); k >= 1;k--)
{
    for (int i = 0; i + k <= m; i++)
    {
        for (int j = 0; j + k <= n; j++)
        {
            if (isMagic(i, j, k))return k;
        }
    }
}
    return 1;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>grid = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};

    cout<<largestMagicSquare(grid)<<endl;
    
    return 0;
}