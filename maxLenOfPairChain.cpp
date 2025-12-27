#include <bits/stdc++.h>
using namespace std;

int findLongestChain(vector<vector<int>> &pairs)
{

    /*
    Pair p2 = [c,d] follows a pair p1 = [a,b] if b < c

    Return the length of longest possible chain
    */

    // Sorting every pair by their ending value
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b)
         { return a[1] < b[1]; });

    int cnt = 1;
    int lastEnd = pairs[0][1];

    // Greedy Selection
    for (int i = 1; i < pairs.size(); i++)
    {
        if (pairs[i][0] > lastEnd)
        {
            cnt++;
            lastEnd = pairs[i][1];
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};

    cout << findLongestChain(pairs) << endl;

    return 0;
}