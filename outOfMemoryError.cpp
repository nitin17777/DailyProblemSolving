#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<ll> original = a;

        unordered_map<int, ll> diff;

        while (m--)
        {
            int b, c;
            cin >> b >> c;

            b--;

            ll curr = original[b] + diff[b];

            ll newVal = curr + c;

            if (newVal > h)
                diff.clear(); // To wipe out all the additions fastly

            else
                diff[b] += c;
        }

        for (int i = 0; i < n; i++)
        {
            cout << original[i] + diff[i] << " ";
        }

        cout << endl;
    }
    return 0;
}