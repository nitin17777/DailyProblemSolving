#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    // we have to insert the given interval in the existing interval
    int n = intervals.size();
    int m = intervals[0].size();

    // Compare the end of last interval with start of the new interval

    vector<vector<int>> ans;

    for (auto curr : intervals)
    {
        // Case when current interval is completely before newinterval
        if (curr[1] < newInterval[0])
        {
            ans.push_back(curr);
        }
        // similarly if interval is completely after
        else if (curr[0] > newInterval[1])
        {
            ans.push_back(newInterval);
            newInterval = curr;
        }

        else
        {
            // Overlapping intervals,so we will merge
            newInterval[0] = min(newInterval[0], curr[0]); // now new start will be the smaller one
            newInterval[1] = max(newInterval[1], curr[1]); // and end to the larger one
        }
    }
    ans.push_back(newInterval);
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> ans = insert(intervals, newInterval);

    for (auto &an : ans)
    {
        for (auto &a : an)
            cout << a << " ";

        cout << endl;
    }
    return 0;
}
