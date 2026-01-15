#include <bits/stdc++.h>
using namespace std;

int longestC(vector<int> &bars)
{
    if (bars.empty())
        return 0;

    sort(bars.begin(), bars.end());

    int longest = 1, curr = 1;

    for (int i = 1; i < bars.size(); i++)
    {
        if (bars[i] == bars[i - 1] + 1)
            curr++;

        else
            curr = 1;

        longest = max(longest, curr);
    }
    return longest;
}

int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
{
    /*
    Grid has n+2 horizontal and m+2 vertical bars creating 1*1 unit cells

    Return the max area of square shaped hole in the grid after removing some bars


    Max area possible would be obtained if same number lines are removed from both

    Remove the max num from both

    */

    // Remove max from both

    // Multiply ((removed + 1) - (removed -1)) both verticallya and horizontally
    // set<int>sth(hBars.begin(),hBars.end());
    // set<int>stb(vBars.begin(),vBars.end());

    // sort(hBars.begin(),hBars.end());
    // sort(vBars.begin(),vBars.end());

    // int maxi1 = hBars[hBars.size()-1] + 1;

    // int mini1 = maxi1 -2;
    // while(sth.count(mini1))
    // {
    //     mini1--;
    // }

    // int maxi2 = vBars[vBars.size()-1] + 1;

    // int mini2 = maxi2 -2;
    // while(stb.count(mini2))
    // {
    //     mini2--;
    // }
    // return (maxi1 - mini1) * (maxi2 - mini2);

    int maxH = longestC(hBars);
    int maxB = longestC(vBars);

    int side = min(maxH, maxB) + 1;

    return side * side;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> hb = {2, 3};
    vector<int> vb = {2};

    cout << maximizeSquareHoleArea(2, 1, hb, vb) << endl;
    return 0;
}