#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> solve(vector<ll> &l)
{
    ll n = l.size();

    /*
    in isoceles trapazoid, two opposite sides are parallel and two sides are of equal lengths

    //give all the lengths which can help in making of this shape

    */

    // now we have to choose 4 nums from given array which satisfy this condition

    unordered_map<ll, ll> freq;
    freq.reserve(n * 2);

    for (auto x : l)
        freq[x]++;

    vector<ll> pairs;
    pairs.reserve(freq.size());
    // to get all those with frequency >= 2
    for (auto &p : freq)
    {
        if (p.second >= 2)
            pairs.push_back(p.first);
    }

    if (pairs.empty())
        return {};

    sort(pairs.begin(), pairs.end());

    // Case 1 : Two or more distinct pairs =>Always possible
    if (pairs.size() >= 2)
    {
        ll c = pairs[0]; // to minimise a-b
        ll a = pairs[1];
        ll b = pairs[1];

        return {a, b, c, c};
    }

    ll c = pairs[0];

    vector<ll> baseList;
    baseList.reserve(n - 2);

    ll used = 0;

    for (auto x : l)
    {
        if (x == c && used < 2)
        {
            used++;
            continue;
        }
        baseList.push_back(x);
    }

    // unable to form 2 bases then
    if (baseList.size() < 2)
        return {};

    sort(baseList.begin(), baseList.end());

    // Checking adj pairs for min difference
    for (int i = 0; i + 1 < baseList.size(); i++)
    {
        ll a = baseList[i];
        ll b = baseList[i + 1];

        if (llabs(a - b) < 2 * c)
        {
            return {a, b, c, c};
        }
    }
    return {};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> l(n);

        for (ll &x : l)
            cin >> x;

        vector<ll> ans = solve(l);

        if (ans.empty())
            cout << "-1";
        else
        {
            for (auto &an : ans)
                cout << an << " ";
        }
        cout << endl;
    }
    return 0;
}
