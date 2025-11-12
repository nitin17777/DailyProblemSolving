#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    // total elements in given date
    vector<int> cnt(10, 0);
    bool possible = false;

    for (int i = 0; i < n; i++)
    {
        int dig;
        cin >> dig;
        cnt[dig]++;

        if (!possible && cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1)
        {
            cout << i + 1 << endl;
            possible = true;
        }
    }

    if (!possible)
        cout << 0 << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
