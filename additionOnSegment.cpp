#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxi(vector<ll> &a)
{
    /*

    Choose two integers l and r =>Assign ai = ai +1 for each i : l<i<r

    Choose any interval and increase value there by 1


    Choose values l and r for each action that :

    After n actions, it's possible to reorder the elements such that a== b

    r-l+1 acquires the largest values as possible while every action

    Return the max possible value fo r-l+1


    */

    int n = a.size();

    ll sum = 0, cntOne = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            cntOne++;

        sum += a[i];
    }

    // Since each non zero element must be incremented atleast once -> cntOne operations out of total are already performed

    ll sum2 = sum - cntOne;

    ll sub = n - sum2 - 1;

    return cntOne - max(0ll, sub);
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
        cout << maxi(a) << endl;
    }

    return 0;
}