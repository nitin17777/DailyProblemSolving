#include <bits/stdc++.h>
using namespace std;

long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
{
    /*
    We have bottomleft and topright coordinates of ith rectangle

    Find the max area of square that can fit inside intersecting region of at least two rectangles


    */

    int n = bottomLeft.size();

    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int left = max(bottomLeft[i][0], bottomLeft[j][0]);
            int right = min(topRight[i][0], topRight[j][0]);
            int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
            int top = min(topRight[i][1], topRight[j][1]);

            if (left < right && bottom < top)
            {
                int side = min(right - left, top - bottom);
                maxi = max(maxi, side * side);
            }
        }
    }
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> bottomLeft = {{1, 1}, {2, 2}, {3, 1}};
    vector<vector<int>> topRight = {{3, 3}, {4, 4}, {6, 6}};

    cout << largestSquareArea(bottomLeft, topRight) << endl;

    return 0;
}