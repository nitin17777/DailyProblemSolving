#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll maxRunTime(int n, vector<int> &batteries)
{

    /*ith battery can run a computer for battries[i] minutes
    We need to run n computer simultaneously using given batteries

    We can insert at most one battery into each computer


    Return the max number of minutes we can run all n computers simultaneously

    to run all n computers for T minutes: total power needed = T * n

    a battery with x power can contribute : min(x,T)

    Total usable power for target time T is: sum(min(battery[i], T))

    //So to run all comps for T minutes ,we must have usable >= T * n

    So : T = usable/n
    */

    ll sum = 0;
    for (ll b : batteries)
        sum += b;

    // max possible time cannot exceed (totalPower /n)
    ll left = 0, right = sum / n, ans = 0;

    // binary search on possible running time T
    while (left <= right)
    {
        ll T = left + (right - left) / 2;

        // Calculating how much power we can use if we target T minutes
        // each battery contributes at most min(b,T)
        ll total = 0;
        for (ll b : batteries)
            total += min(b, T);

        // to run n comps for T minutes , we need total usable power > = T*n
        if (total >= T * n)
        {
            ans = T;
            left = T + 1;
        }
        else
        {
            right = T - 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> b = {3, 3, 3};
    cout << maxRunTime(2, b) << endl;

    return 0;
}