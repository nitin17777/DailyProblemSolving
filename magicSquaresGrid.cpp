#include <bits/stdc++.h>
using namespace std;

bool valid(vector<vector<int>> &g, int i, int j)
{
    // checking for unique elements in grid
    unordered_set<int> st;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            int val = g[i + r][j + c];
            if (val < 1 || val > 9 || st.count(val))
                return false;

            st.insert(val);
        }
    }

    // We have sum of 1st row now for reference
    int sum = g[i][j] + g[i][j + 1] + g[i][j + 2];

    // Doing rowsum check
    for (int r = 1; r < 3; r++)
    {
        int su = 0;
        for (int c = 0; c < 3; c++)
        {
            su += g[i + r][j + c];
        }
        if (su != sum)
            return false;
    }

    // Doing col check similarly
    for (int c = 1; c < 3; c++)
    {
        int su = 0;
        for (int r = 0; r < 3; r++)
        {
            su += g[r + i][c + j];
        }
        if (su != sum)
            return false;
    }

    // Doing diagonal check

    int d1 = g[i][j] + g[i + 1][j + 1] + g[i + 2][j + 2];
    int d2 = g[i][j + 2] + g[i + 1][j + 1] + g[i + 2][j];

    return d1 == sum && d2 == sum;
}

int numMagicSquaresInside(vector<vector<int>> &grid)
{
    /*
    Magic square is a 3*3 grid filled with disticnt number from 1 to 9 such that each row, col and both diagonals have same sum

    Return the number of magic squares present in given grid
    */

    int row = grid.size();
    int col = grid[0].size();

    if (row < 3 || col < 3)
        return 0;

    int cnt = 0;

    // We just need to check for every 3*3 possible square if their rowSum = colSum = diagonalSum

    for (int i = 0; i <= row - 3; i++)
    {
        for (int j = 0; j <= col - 3; j++)

            if (valid(grid, i, j))
                cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    cout << numMagicSquaresInside(grid) << endl;

    return 0;
}