#include<bits/stdc++.h>
using namespace std;

int largestSubmatrix(vector<vector<int>>& mat)
{
    int m = mat.size(),n=mat[0].size();


    //we can rearrange the columns of the matrix in any order

    //Return the area of largest sub matrix where eery element of submat is 1

    //Check the number of 1's in same row

    //Building heights
    for(int j=0;j<n;j++)
    {
        for(int i=1;i<m;i++)
        {
            if(mat[i][j] == 1)
            {
                //Helps to calculate how many consecutive 1's including itself are above it
                mat[i][j] += mat[i-1][j];
            }
        }
    }

    int maxArea = 0;
    //Processing each row
    for(int i = 0;i<m;i++)
    {
        vector<int>heights = mat[i];

        sort(heights.begin(),heights.end(), greater<int>());

        //Now calculate max area for this row
        for(int j = 0;j<n;j++)
        {
            int area = heights[j] * (j+1);
            maxArea = max(maxArea,area);
        }
    }
    return maxArea;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>mat = {{0,0,1},{1,1,1},{1,0,1}};
    cout<<largestSubmatrix(mat)<<endl;
    return 0;
}