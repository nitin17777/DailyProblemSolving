#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(ll x, ll y, ll z)
{
    // determine whether there exists3 integers a,b,c satisfying:
    /*  a&b=x
        b&c=y
        a&c=z
    */

    ll b = x | y;
    ll a = x | z;
    ll c = y | z;

    return ((a & b) == x) && ((b & c) == y) && ((a & c) == z);

    // If bit in x == 1, then bit in a and b must be 1
    // If bit in  y == 1 , then bit in b and c must be 1
    // If bit inn z == 1 ,then bit in a and c must be 1

    // Thus wherever a pair mask has 1 , both numbers must have 1
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll x, y, z;
        cin >> x >> y >> z;

        cout << (isPossible(x, y, z) ? "Yes" : "No") << endl;
    }
    return 0;
}
