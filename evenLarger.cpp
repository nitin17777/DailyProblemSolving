#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll minNum(vector<int> &a)
{
    /*
    Array is called good if for any subarray of length atleast 2 sum of elements at even indices is greater than or equal to sum of elements at odd indices(1 based indexing)

    In one operation,  we can decrease any element by 1, return min number of ops required to make the given array good

    */
    int n = a.size();

    vector<ll> b(n, 0);
    ll ans = 0;

    for (int i = 0; i < n; i += 2)
    {
        ll mn = a[i];
        if (i >= 2)
        {
            mn = min(mn, (ll)a[i - 1] - b[i - 2]);
        }
        if (i + 1 < n)
        {
            mn = min(mn, (ll)a[i + 1]);
        }

        b[i] = mn;

        ans += (a[i] - b[i]);
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

        vector<int> a(n);
        for (auto &i : a)
            cin >> i;

        cout << minNum(a) << endl;
    }
    return 0;
}