#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int k)
{

    // If no suitable partiton, return -1

    /*We have to split a into m subarrays such that :


    Median of the array of the medians must be k
    Length of each subarray must be odd

    */

    if (n == 1)
    {
        if (k == 1)
            return {1};
        else
            return {};
    }

    if (k == 1 || k == n)
        return {};

    // We have to give the left boundary of every division of subarray

    // If k is even : Take 1 length middle
    // If k is odd : Take 3 length middle

    vector<int> ans;

    ans.push_back(1);

    ans.push_back(k - k % 2);
    ans.push_back(k + 1 + k % 2);

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
        int n, k;
        cin >> n >> k;

        vector<int> ans = solve(n, k);

        if (ans.size() == 0)
        {
            cout << -1 << endl;
            continue;
        }

        cout << ans.size() << endl;
        for (auto &x : ans)
            cout << x << " ";

        cout << endl;
    }
    return 0;
}