#include <bits/stdc++.h>
using namespace std;

// Found it bit hard  though it was just a div3 b

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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i += 2)
        {
            for (int j = i; j <= n; j *= 2)
            {
                for (int k = i * 2; k <= n; k *= 2)
                {
                    if (a[k / 2] > a[k])
                        swap(a[k / 2], a[k]);
                }
            }
        }

        if (is_sorted(a.begin(), a.end()))
            cout << "Yes" << endl;

        else
            cout << "No" << endl;
    }
    return 0;
}