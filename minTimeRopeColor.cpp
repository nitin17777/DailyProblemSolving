#include <bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int> &neededTime)
{
    // two consecutive chars can't be the same
    // remove the min char with cost given

    /// Algo: keep stretching the window until same chars are there

    int n = neededTime.size();
    int cost = 0;

    for (int i = 1; i < n; i++)
    {
        if (colors[i] == colors[i - 1])
        {
            cost += min(neededTime[i], neededTime[i - 1]);

            neededTime[i] = max(neededTime[i], neededTime[i - 1]);
        }
    }
    return cost;
}

int main()
{

    string s = "aaabbbabbbb";
    vector<int> neededTime = {3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1};
    cout << minCost(s, neededTime) << endl;

    return 0;
}
