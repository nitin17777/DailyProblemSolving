#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, vector<int> &b)
{

    int n = a.size();
    int m = b.size();

    /*
    jth operation would be to choose  the boards and change the integr written on it to bj

    */

    vector<int> arr;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (auto &x : a)
        arr.push_back(x);
    for (auto &x : b)
        arr.push_back(x);

    // now we have all elements in arr

    int ans = 0;
    int sz = arr.size();

    for (int i = sz - 1; i >= sz - n; i--)
    {
        ans += arr[i];
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
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        cout << solve(a, b) << endl;
    }
    return 0;
}