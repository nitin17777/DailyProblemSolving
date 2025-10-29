#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> smallest(vector<ll> &nums)
{
    int n = nums.size();

    // gcd of full given array
    ll g = nums[0];
    for (int i = 1; i < n; i++)
    {
        g = __gcd(g, a[i]);
    }

    if (g == 1)
        return 2;

    ll ans = -1;
    for (ll x = 2; x <= 1000000000; x++)
    {
        if (__gcd(x, g) == 1)
        {
            ans = x;
            break;
        }
        return ans;
    }
}

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
        cout << smallest(nums) << endl;
    }
    return 0;
}
