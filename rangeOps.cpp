#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll maxArr(vector<int> &a)
{

    /*

    Choose a range [l,r] (1<= l <= r<= n)and replace the value of elements al , al+1,al+2 ...... with l +r

    Return the max possible total array sum if we can perform this operation at most once

    ALGO :

    Find the longest subarray with min sum such that no element greater than n comes in that array

    //WE need to find the max subarray sum
    */

    int n = a.size();
    ll original = 0;

    for (ll x : a)
        original += x;

    // made array b => Gain array
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i] = 2LL * (i + 1) - a[i];
    }

    ll best = 0, curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr = max(0LL, curr + b[i]); //
        best = max(best, curr);
    }
    return original + best;
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

        vector<int> arr(n);
        for (auto &x : arr)
            cin >> x;

        cout << maxArr(arr) << endl;
    }

    return 0;
}