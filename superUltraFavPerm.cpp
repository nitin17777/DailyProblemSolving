#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n)
{
    /*

    Permutation is of size consisting of numbers from 1 to n only

    construct a permutation such that sum of adjacent elements is composite over every interval,if not possible return -1;

    we should avoid even odd adjacency as much as possible
    */

    if (n < 5)
        return {-1};

    vector<int> ans;

    // Pushing all evens first
    for (int i = 2; i <= n; i += 2)
    {
        {
            if (i != 4)
                ans.push_back(i);
        }
    }

    // 4 and 5 acts as a valid bridge bw odd and even
    ans.push_back(4);
    ans.push_back(5);

    // Now pushing odds
    for (int i = 1; i <= n; i += 2)
    {
        if (i != 5)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans = solve(n);

        for (auto &x : ans)
            cout << x << " ";

        cout << endl;
    }
    return 0;
}