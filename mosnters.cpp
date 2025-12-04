#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> order(vector<ll> &h, ll k)
{

    /*

    Decrease k from the greatest element everytime, if several greates elements are there, on with smaller index will be decresed,

    Keep pushing elements in ans array as soon as they become less than equal to 0


    //Determine the order in which they will move

    //

    ALGO:

    push element with min mod first, if many start with smaller index

    //store (index,mod) pair

    sort with mod value and if mod same , consider the smaller index first
    */

    ll n = h.size();
    vector<pair<ll, ll>> p; // index,mod

    for (int i = 0; i < n; i++)
    {
        ll mod = h[i] % k;
        if (mod == 0)
            mod = k;
        p.push_back({i + 1, mod});
    }

    stable_sort(p.begin(), p.end(), [&](auto &a, auto &b)
                { return a.second > b.second; });

    vector<ll> ans;
    for (auto &pr : p)
    {
        ans.push_back(pr.first);
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
        ll n, k;
        cin >> n >> k;

        vector<ll> h(n);
        for (auto &x : h)
            cin >> x;

        vector<ll> ans = order(h, k);
        for (auto &an : ans)
            cout << an << " ";

        cout << endl;
    }

    return 0;
}