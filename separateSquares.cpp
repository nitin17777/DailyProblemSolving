#include <bits/stdc++.h>
using namespace std;

double separateSquares(vector<vector<int>> &squares)
{

    /*
    squares[i] = [xi,yi,li]

    Represents coordinates of bottom left point and side length of square parallel to x axis


    Find the min y coordinate value of a horizontal line such that total area of squares above the line = total areas of squares below the line
    */

    double low = 1e18, high = -1e18;

    for (auto &s : squares)
    {
        low = min(low, (double)s[1]);
        high = max(high, (double)(s[1] + s[2]));
    }

    // Doing binary search now , with 60 iterations, because 60 iterations are enough for 1e-5 accuracy

    for (int iter = 0; iter < 60; iter++)
    {
        double mid = (low + high) / 2.0;

        // Area below and above the line
        double below = 0.0, above = 0.0;

        // Computing area contributions for each square
        for (auto &s : squares)
        {
            double y = s[1];
            double l = s[2];

            /*Computing height of square part below the line

            mid <= y     =>0(Line is below the square)
            mid >= y +l  =>1 (Entire square is below)
            else          => mid - y (partial overlap)

            */

            double heightBelow = max(0.0, min(mid - y, l));

            double areaBelow = heightBelow * l;

            double totalArea = l * l;

            below += areaBelow;
            above += (totalArea - areaBelow);
        }
        if (below < above)
        {
            low = mid;
        }
        else
            high = mid;
    }
    return (low + high) / 2.0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> sq = {{0, 0, 1}, {2, 2, 1}};
    cout << separateSquares(sq) << endl;
    return 0;
}