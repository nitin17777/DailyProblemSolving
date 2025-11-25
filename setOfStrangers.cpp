#include <bits/stdc++.h>
using namespace std;

// int minNum()
// {
//     //Stranger if all pairs of cells in the set are strangers

//     //Min numeber of steps to make the whole table the same color

// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        int maxColor = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                maxColor = max(maxColor, a[i][j]); // just to avoid making array of unnecessary size
            }
        }

        // hasColor[c] = 1 -> If color c+1 is present in the grid
        // hasBad[c] = 1 -> If color c+1 has atleast one adjacent pair

        vector<int> hasColor(maxColor, 0);
        vector<int> hasBad(maxColor, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int c = a[i][j] - 1;

                hasColor[c] = 1; // marking that this color is present in grid

                if (i + 1 < n && a[i][j] == a[i + 1][j]) // vertical neighbour
                {
                    hasBad[c] = 1;
                    // if two adj neiighbour share same color , then color would need 2 operations
                }

                if (j + 1 < m && a[i][j] == a[i][j + 1]) // horizontal neighbour
                {
                    hasBad[c] = 1;
                }
            }
        }
        int sumColor = 0;
        int sumBad = 0;
        int maxBad = 0;

        for (int i = 0; i < maxColor; i++)
        {
            sumColor += hasColor[i]; // Counting how many colors appear
            sumBad += hasBad[i];     // counting how many colors need 2 ops

            maxBad = max(maxBad, hasBad[i]);
        }

        int ans = sumColor + sumBad - 1 - maxBad;
        cout << ans << endl;
    }

    return 0;
}
