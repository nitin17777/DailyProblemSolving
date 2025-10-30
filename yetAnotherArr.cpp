#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        for (ll x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53})
        {
            int ok = 0;
            for (ll i : nums)
            {
                if (i % x != 0)
                {
                    ok = 1;
                    break;
                }
            }

            if (ok)
            {
                cout << x << endl;
                break;
            }
        }
    }
    return 0;
}
