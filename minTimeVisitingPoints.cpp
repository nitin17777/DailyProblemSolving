#include <bits/stdc++.h>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    /*
    In one second we can move vertically , horizontally, diagonally root 2 units


    Return the min time to visit all point given
    */

    // Just find the difference btween 2 consective .first of all elements

    int ans = 0;
    for (int i = 0; i + 1 < points.size(); i++)
    {

        //{{1,1},
        // {3,4},
        //{-1,0}};
        int diff1 = abs(points[i + 1][0] - points[i][0]);
        int diff2 = abs(points[i + 1][1] - points[i][1]);

        ans += max(diff1, diff2);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> p = {{1, 1},
                             {3, 4},
                             {-1, 0}};
    cout << minTimeToVisitAllPoints(p) << endl;

    return 0;
}