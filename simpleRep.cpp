#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
/*
bool solve(ll x, ll k)
{
    /*
    To obtain new num y, repeat k times the decimal representation of number x without leading zero

    Check if y is prime or not



    string str = "";
    while (k != 0)
    {
        if (x > 9)
            str += to_string(x);

        else
            str += char('0' + x);

        k--;
    }

    ll num = stoi(str);

    return isPrime(num);
}

*/

// Important Observation: Repeating a number more than twice creates a composite number except case of 11

bool solve(ll x, ll k)
{
    if (x == 1 && k == 2)
        return true;

    if (k > 1)
        return false; // Number would be composite then

    return isPrime(x); // if k == 1 wala case
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll x, k;
        cin >> x >> k;

        cout << (solve(x, k) ? "Yes" : "No") << endl;
    }
    return 0;
}