#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<vector<int>> &grid)
{

    int n = grid.size();

    // A grid is valid if all the cells above the main diagonal are zeroes

    // Main digaonal : Starts from (1,1) and ends at (n,n)

    // Return the min steps needed to make the grid valid else return -1

    // n-1 grid -> 1
    //  1 -> n-1

    // counting trailing zeores for each row
    vector<int> trailing(n);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[i][j] == 0)
                cnt++;

            else
                break;
        }
        trailing[i] = cnt;
    }

    int swaps = 0;

    // Now time to place correct row at their position

    for (int i = 0; i < n; i++)
    {
        int needed = n - i - 1;
        int j = i;

        // Finding the row that satisfies the given needs
        while (j < n && trailing[j] < needed)
            j++;

        if (j == n)
            return -1; // Unable to find any of such row

        // Swap until the required row is in correct position
        while (j > i)
        {
            swap(trailing[j], trailing[j - 1]);
            swaps++;
            j--;
        }
    }
    return swaps;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
    cout << minSwaps(grid) << endl;

    return 0;
}