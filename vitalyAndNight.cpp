#include <bits/stdc++.h>
using namespace std;

// int count(vector<int> &a)
// {
//     int cnt = 0;
//     if (a[0] == 1)
//         cnt = 1;

//     for (int i = 1; i < a.size(); i++)
//     {
//         if (a[i - 1] != 1)
//         {
//             if (a[i] == 1)
//                 cnt++;
//         }
//     }
//     return cnt;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(2 * m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * m; j++)
        {
            cin >> a[i][j];
        }
    }

    int cnt = 0;

    // Now use that count function for every row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * m; j += 2)
        {
            if ((a[i][j] == 1) || a[i][j + 1] == 1)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}