#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n)
{
    // we have to construct an array of length 2n such that each integer from i to n appears exactly twice in the array

    // for each x ,distance between it's two occurrence will be multiple of x

    // construct the final array

    vector<int> ans;

    for (int i = n; i >= 1; i--)
        ans.push_back(i);

    ans.push_back(n);

    for (int i = 1; i < n; i++)
        ans.push_back(i);

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> ans = solve(n);
        for (auto &an : ans)
            cout << an << " ";

        cout << endl;
    }

    return 0;
}
