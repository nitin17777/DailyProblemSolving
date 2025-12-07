#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll maxi(vector<ll> &a, vector<ll> &b)
{
    int n = a.size();

    ll mx = 0, mn = 0;

    for (int i = 0; i < n; i++)
    {
        ll newmx = max(mx - a[i], b[i] - mn);
        ll newmn = min(mn - a[i], b[i] - mx);

        mx = newmx, mn = newmn;
    }
    return mx;
}

/*
ll maxi(vector<ll> &a, vector<ll> &b)
{
    /*

    Red card -> Score becomes k -ai
    Blue Card -> Score becomes bi - k

    Return max possible score niko cna obtain

    int n = a.size();

    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        ll sa = s - a[i];
        ll sb = b[i] - s;

        s = max(sa, sb);
    }
    return s;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (auto &x : a)
            cin >> x;

        for (auto &x : b)
            cin >> x;

        cout << maxi(a, b) << endl;
    }

    return 0;
}