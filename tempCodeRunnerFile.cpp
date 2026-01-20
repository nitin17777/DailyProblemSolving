#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size();

    if(m==0)return false;

    int n = matrix[0].size();

    int row = 0,col = n-1;

    while(row <m && col >= 0)
    {
        if(matrix[row][col] == target)return true;

        else if(matrix[row][col] > target)col--;

        else row++;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    cout<<(searchMatrix(matrix,5)?"True": "No")<<endl;
    return 0;
}