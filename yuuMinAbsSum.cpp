#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    int n = a.size();

    /*
    the final exp: | (a2 - a1) + (a3-a2)+ ...(an - an-1) | = |an-a1|

    so only both end points should be equal and other places won't affect anything

    */

    if (a[0] == -1 && a[n - 1] == -1)
    {
        a[0] = 0;
        a[n - 1] = 0;
    }

    if (a[0] == -1)
        a[0] = a[n - 1];

    if (a[n - 1] == -1)
        a[n - 1] = a[0];

    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] == -1)
        {
            a[i] = 0;
        }
    }
    return a;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        vector<int> ans = solve(a);

        int diff = 0;
        for (int i = 0; i < n - 1; i++)
        {
            diff += a[i + 1] - a[i];
        }
        cout << abs(diff) << endl;

        for (auto &an : ans)
        {
            cout << an << " ";
        }
        cout << endl;
    }
    return 0;
}
