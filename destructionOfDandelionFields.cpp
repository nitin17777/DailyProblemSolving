#include <bits/stdc++.h>
using namespace std;

#define ll long long
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

ll canCut(vector<ll> &dandelions)
{
    // ith filed has ai dandelions

    // initially landmower is off

    // if odd number of flowers then it toggles it's state

    // if lawnmower is on it will cut all dandelions in field otherwise no flower will be cut down

    // find the max number of dandlions he can cut

    // landmower can only toggle if any odd number comes

    // so start the landmower put all even nums  then

    ll evenSum = 0;
    ll total = accumulate(dandelions.begin(), dandelions.end(), 0LL);

    vector<ll> odds;

    for (auto fl : dandelions)
    {
        if (fl % 2 == 0)
            evenSum += fl;
        else
            odds.push_back(fl);
    }

    if (odds.size() == 1) // because then machine would never stop
        return total;

    if (odds.empty())
        return 0; // machine never starts

    sort(odds.rbegin(), odds.rend()); // descending sort

    ll k = (odds.size() + 1) / 2;

    ll oddSum = 0;

    for (int i = 0; i < k; i++)
        oddSum += odds[i]; // since we can only take largest k/2 odds only

    return evenSum + oddSum;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> dandelions(n);

        for (int i = 0; i < n; i++)
        {
            cin >> dandelions[i];
        }

        cout << canCut(dandelions) << endl;
    }

    return 0;
}