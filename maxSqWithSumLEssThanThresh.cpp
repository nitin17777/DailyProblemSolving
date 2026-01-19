#include <bits/stdc++.h>
using namespace std;

int maxSideLength(vector<vector<int>> &mat, int threshold)
{

    int m = mat.size();
    int n = mat[0].size();

    // We have to return the max side length of square with sum less than or equal to threshold else return 0

    vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0)); // Matrix for prefix sum

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pref[i][j] = mat[i - 1][j - 1] + // current cell
                         pref[i - 1][j] +    // top
                         pref[i][j - 1] -    // left
                         pref[i - 1][j - 1]; // Removing double counted
        }
    }

    int low = 0, high = min(m, n), ans = 0;

    while (low <= high)
    {
        int mid = (high + low) / 2; // current square side to test

        bool possible = false;

        for (int i = mid; i <= m && !possible; i++)
        {
            for (int j = mid; j <= n; j++)
            {

                // Calculatign sum of current mid * mid square using prefix sum

                int sum = pref[i][j]                // Took full area
                          - pref[i - mid][j]        // Removing extra part at top
                          - pref[i][j - mid]        // removing extra area t left
                          + pref[i - mid][j - mid]; // Adding back the twice removed area

                if (sum <= threshold)
                {
                    possible = true;
                    break;
                }
            }
        }

        if (possible)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> mat = {{1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};

    cout << maxSideLength(mat, 4) << endl;
    return 0;
}