#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool solve(vector<int> &a)
{
    int n = a.size();
    if (n <= 1)
        return true;

    /*
    In each step we can: decrease a[i-1] by 1 then increase a[i+1] by 1
                         decrease a[i+1] by 1 then increase a[i-1] by 1


    Return true if we can make all elements equal after any number of operations
    */

    /*

                        IMPORTANT

    We can make all elements of array equal to k iff sum(a)/k
     and that value would be sum(a) /k

    So final required condition: sum(od) % od.size() ==0
                                 sum(ev) % ev.size() ==0

                            and : sum(od)/od.size() == sum(ev) / ev.size()

    */

    // Summing even and odd position elements
    ll odds = 0, evs = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            odds += a[i];

        else
            evs += a[i];
    }

    // counting even and size
    int odc = n / 2, evc = n / 2;
    if (n & 1)
        evc++;

    // Main condition
    if ((odds % odc) != 0 || (evs % evc != 0) || ((odds / odc) != (evs / evc)))
        return false;
    return true;
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

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << (solve(a) ? "Yes" : "No") << endl;
    }
    return 0;
}