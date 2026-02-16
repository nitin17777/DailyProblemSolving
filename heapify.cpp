#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a)
{
    int n = a.size();

    vector<int> temp = a;
    // Determine if we can make the array sorted or not

    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] > a[n - i - 1])
            swap(a[i], a[n - i - 1]);
    }

    sort(temp.begin(), temp.end());

    if (temp == a)
        return true;

    return false;
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
        cout << (solve(a) ? "Yes" : "No") << endl;
    }
    return 0;
}