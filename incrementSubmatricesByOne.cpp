#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
{

    vector<vector<int>> diff(n + 1, vector<int>(n + 1));

    // marking only the corners for each query ,which avoids updating all n*n cells for every query
    for (auto &q : queries)
    {
        int r1 = q[0], c1 = q[1];
        int r2 = q[2], c2 = q[3];

        diff[r1][c1] += 1; // Added 1 at top left corner

        if (c2 + 1 < n)
            diff[r1][c2 + 1] -= 1;
        if (r2 + 1 < n)
            diff[r2 + 1][c1] -= 1;
        if (r2 + 1 < n && c2 + 1 < n)
            diff[r2 + 1][c2 + 1] += 1;
    }

    // constructing prefix sum horizontally
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            diff[i][j] += diff[i][j - 1];
        }
    }

    // constructing prefix sum horizontally
    for (int j = 0; j < n; j++)
    {

        for (int i = 1; i < n; i++)
        {
            diff[i][j] += diff[i - 1][j];
        }
    }

    // Building the final matrix now
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = diff[i][j];
        }
    }
    return ans;
}

/* Getting TLE with this method
vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries)
{
    //we initially have n*n matrix that is filled with 0

    //for each query{i} = (row1i, col1i, row2i, col2i)

    //Add 1 to every element for row1i <= x <= row2i and col1i <= y <= col2i

    //return the matrix after performing every query
    vector<vector<int>>arr(n,vector<int>(n,0));

    for(auto nums : queries)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0 ; j<n;j++)
            {
                if(i>=nums[0] && i<=nums[2] && j>=nums[1] && j<=nums[3])
                {
                    arr[i][j] += 1;
                }
            }
        }
    }

    return arr;
}*/

int main()
{
    vector<vector<int>> queries = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    vector<vector<int>> ans = rangeAddQueries(3, queries);

    for (auto &an : ans)
    {
        for (auto &a : an)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
