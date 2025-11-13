#include <bits/stdc++.h>
using namespace std;

// int maxValue(vector<vector<int>> &a, int m, int n)
// {
/* cell at intersection of i and jth column contains number aij

// we are given a matrix and if  i==r or j==c, decrease the value at a[i][j] and by doing this operation find the min possible value

// Find the minmal maximum value in matrix a after performing one operation exactly

choose any row r and one column c, then for evry cell that is in r and c decrease it's value by 1

//And after doing this peration once, make the max element in matrix as small as possible

*/

//     int maxVal = INT_MAX;
//     vector<pair<int, int>> pos;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (a[i][j] > maxVal)
//             {
//                 maxVal = a[i][j];
//                 pos = {{i, j}};
//             }

//             else if (a[i][j] == maxVal)
//             {
//                 pos.push_back({i, j});
//             }
//         }
//     }

//     unordered_set<int> rows, cols;

//     for (auto [r, c] : pos)
//     {
//         rows.insert(r);
//         cols.insert(c);
//     }

//     if (rows.size() == 1 || cols.size() == 1)
//         return maxVal = -1;

//     return maxVal;
// }

int maxValue(vector<vector<int>> &a, int n, int m)
{

    int mx = 0, cntmx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > mx)
            {
                mx = a[i][j];
                cntmx = 1;
            }
            else if (a[i][j] == mx)
                cntmx++;
        }
    }

    // Now marking those row and cols haviing mx in them
    vector<int> r(n), c(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == mx)
            {
                r[i]++;
                c[j]++;
            }
        }
    }

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // r[i] and c[i] => how many mx elements are there in any row or coloumn
            //  if max value will decrease for sure
            if (r[i] + c[j] - (a[i][j] == mx) == cntmx)
            {
                flag = 1;
            }
        }
    }
    return mx - flag;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        cout << maxValue(a, n, m) << endl;
    }
    return 0;
}
