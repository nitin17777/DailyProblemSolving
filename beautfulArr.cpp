#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> solve(ll n, ll k, ll b, ll s)
{

    // Beauty of an array  =  every element divided by k, rounded up and then sum of array

    // We have to find this array a such that beauty is equal to b and sum of elements is s

    // sum of array cannot be less than b * k => s >= b*k

    ll minSum = b * k;
    ll maxSum = minSum + n * (k - 1);
    if (s < minSum || s > maxSum)
        return {};

    vector<ll> ans(n, 0);
    ans[0] = minSum;

    ll rem = s - minSum;

    // Now distribute this rem in remaining elements such that every element is under k -1, so that it won't be able to contribute anything to the beauty

    for (int i = 0; i < n && rem > 0; i++)
    {
        ll add = min(rem, k - 1);
        ans[i] += add;
        rem -= add;
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
        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        vector<ll> ans = solve(n, k, b, s);
        if (ans.size() != 0)
        {
            for (auto &x : ans)
                cout << x << " ";

            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}