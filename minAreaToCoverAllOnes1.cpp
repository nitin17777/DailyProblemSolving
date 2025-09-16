#include<bits/stdc++.h>
using namespace std;

int minimumArea(vector<vector<int>>& grid)
{
    //find a rectangle with smallest area such that all 1's in grid lies inside triangle

    int m = grid.size();
    int n = grid[0].size();

    int minRow= INT_MAX, maxRow=INT_MIN; 
    int minCol = INT_MAX , maxCol = INT_MIN;

    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(grid[i][j] == 1)
            {
                minRow = min(minRow,i);
                maxRow = max(maxRow ,i);
                minCol = min(minCol,j);
                maxCol = max(maxCol,j);
            }
        }
    }

    if(minRow == INT_MAX)return 0;

    int height = maxRow - minRow +1;
    int width = maxCol - minCol + 1;

    return height*width;
}

int main()
{
    vector<vector<int>> grid = {
        {0,1,0}, {1,0,1}
    };

    cout<<minimumArea(grid)<<endl;
    return 0;
    
}
