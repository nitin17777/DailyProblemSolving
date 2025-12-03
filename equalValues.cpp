#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll minCost(vector<ll> &a)
{
    /*

    Choose a position i and make all elements to left of i equal to ai and cost = (i-1) * ai

    Choose a position i and make all elements to right of i equal to ai and cost = (n−i) * ai

    What would be the minimum total cost to make all elements of array equal


    We are checking if we make the whole array equal to this number x how costly will it be  and then picking the cheapest option at the end

    */

    int n = a.size();

    ll ans = LLONG_MAX;

    int i = 0;
    while (i < n)
    {

        // j will move to find the end of block till we find a[i]
        int j = i;
        while (j < n && a[j] == a[i])
            j++;

        ll x = a[i];
        ll left = i;
        ll right = n - j;

        ll cost = x * (left + right);

        ans = min(cost, ans);

        // Move i to next block
        i = j;
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
        int n;
        cin >> n;

        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;

        cout << minCost(a) << endl;
    }
    return 0;
}