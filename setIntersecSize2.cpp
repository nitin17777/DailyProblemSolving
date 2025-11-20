#include <bits/stdc++.h>
using namespace std;

int intersectionSizeTwo(vector<vector<int>> &intervals)
{
    /*intervals[i] = starti,endi =>Represents all the integers from starti to endi inclusively

    Containing set => Array of nums where each interval from intervals has at least two integers in nums



    ALGO: We should have max overlapped elements to minimise the sizeof nums

    */

    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b)
         {
             if (a[1] == b[1])
                 return a[0] > b[0];
             return a[1] < b[1];
         });

    int p1 = INT_MIN, p2 = INT_MIN;

    int count = 0;

    for (auto &in : intervals)
    {
        int l = in[0];
        int r = in[1];

        bool has_p1 = (p1 >= l && p1 <= r);
        bool has_p2 = (p2 >= l && p2 <= r);

        if (has_p1 && has_p2)
        {
            // already have 2 points → do nothing
            continue;
        }
        else if (has_p2)
        {
            // only one point inside → add 1 more at r
            count++;
            p1 = p2;
            p2 = r;
        }
        else
        {
            // none inside → add 2 points: r-1, r
            count += 2;
            p1 = r - 1;
            p2 = r;
        }
    }
    return count;
}

int main()
{

    vector<vector<int>> intervals = {{1, 3}, {3, 7}, {8, 9}};
    cout << intersectionSizeTwo(intervals) << endl;
    return 0;
}
