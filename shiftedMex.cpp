#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{

    int n = a.size();
    sort(a.begin(), a.end());

    int mini = INT_MAX;
    int k = 0;
    while (k < n)
    {
        if (a[k] != 0)
        {
            mini = a[k];
            break;
        }
        else
            k++;
    }

    for (auto &x : a)
    {
        x -= mini;
    }

    int mex = 0;

    for (int i = 1; i < n; i++)
    {
        // -1, 0, 1, 2, 4
        // 0, 0, 0, 1,2,3 -> 4

        //-1,1,2,3,4,5,6

        // 0,0,1,2

        if (a[i] != mex)
            mex++;

        else if (a[i] > mex)
            break;
    }
    return mex;
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

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a) << endl;
    }
    return 0;
}