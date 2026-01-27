#include <bits/stdc++.h>
using namespace std;

bool adj(int r1, int c1, int r2, int c2)
{
    return max(abs(r1 - r2), abs(c1 - c2)) == 1; // Since two cells would be adjacent if atleast difference in row and col = 1
}

string solve(vector<vector<char>> &grid)
{
    // Given a 3*3 grid with letters in each cell.
    // Determine the lexicographically smallest possible word of length 3 that can be found in the grid

    /*
    Go to the smallest letter possible first
    Then from there, go to the least possible char in it's vicinity
    and do the same for the last
    */

    vector<string> v;

    for (int r1 = 0; r1 < 3; r1++)
    {
        for (int c1 = 0; c1 < 3; c1++)
        {
            for (int r2 = 0; r2 < 3; r2++)
            {
                for (int c2 = 0; c2 < 3; c2++)
                {
                    for (int r3 = 0; r3 < 3; r3++)
                    {
                        for (int c3 = 0; c3 < 3; c3++)
                        {
                            // Ensuring all cells to be different
                            if ((r1 == r2 && c1 == c2) ||
                                (r2 == r3 && c2 == c3) ||
                                (r3 == r1 && c3 == c1))
                                continue;

                            // Checking for adjacency
                            if (!adj(r1, c1, r2, c2))
                                continue;
                            if (!adj(r2, c2, r3, c3))
                                continue;

                            string word = "";

                            word += grid[r1][c1];
                            word += grid[r2][c2];
                            word += grid[r3][c3];

                            v.push_back(word);
                        }
                    }
                }
            }
        }
    }

    return *min_element(v.begin(), v.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> grid(3, vector<char>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << solve(grid) << endl;
    return 0;
}