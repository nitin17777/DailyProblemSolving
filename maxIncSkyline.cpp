#include <bits/stdc++.h>
using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
{

    int n = grid.size();
    /*grid[r][c] = Height of building located in block at row r and col c


    We cnan inncrase the height of every building by any amount

    Height of 0th building cna also be increased

    Return the max total sum tha the height of buildings can be increased by without chaneging the city's skyline from any cardinal direction

    */

    // we can go for the minimum of the maximum elements from it's respective row and col

    // Make a new array consisting of min(max elements in row, col)

    // Find the max of each row and col first
    vector<int> row;
    for (int r = 0; r < n; r++)
    {
        int maxi = 0;
        for (int c = 0; c < n; c++)
        {
            maxi = max(maxi, grid[r][c]);
        }
        row.push_back(maxi);
    }
    // Got the row array consisting of required max of each row now

    vector<int> col;
    for (int c = 0; c < n; c++)
    {
        int maxi = 0;
        for (int r = 0; r < n; r++)
        {
            maxi = max(maxi, grid[r][c]);
        }
        col.push_back(maxi);
    }

    // Got the final row and col array

    // Make the array now
    vector<vector<int>> temp = grid;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ele = min(row[i], col[j]);
            temp[i][j] = ele;
        }
    }

    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost += temp[i][j] - grid[i][j];
        }
    }
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    cout << maxIncreaseKeepingSkyline(grid) << endl;

    return 0;
}