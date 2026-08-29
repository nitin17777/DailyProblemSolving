#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        vector<ll> s = a;
        sort(s.begin(), s.end());

        unordered_map<ll,int> cnt;
        for (auto &x : a) cnt[x]++;

        vector<ll> cands = a;
        for (auto &x : a) if (x % 2 == 0) cands.push_back(x/2);

        ll best = 0;
        for (ll x : cands)
        {
            ll ge = n - (lower_bound(s.begin(), s.end(), x) - s.begin());
            ll bonus = cnt.count(2*x) ? cnt[2*x] : 0;
            best = max(best, ge + bonus);
        }
        cout << best << '\n';
    }
    return 0;
}