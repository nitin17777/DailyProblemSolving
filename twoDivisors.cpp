#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll a, ll b)
{

    if (b % a == 0)
    {
        return b * (b / a);
    }
    // ll lcm = a * b / __gcd(a, b);
    ll lcm = (a / __gcd(a, b)) * b; // As division would redue the number first and later we can easily multiply
    return lcm;
}

/*
int solve(int a, int b)
{
    /*1 < a < b < x
    a and b are largest divisors of number x

    Find x

    if (a % b == 0)
        return a;

    if (b % a == 0)
        return b;

    int i = 2, j = 2;

    while (a == b)
    {
        if (a > b)
        {
            b *= j;
            j++;
        }

        if (b > a)
        {
            a *= i;
            i++;
        }
    }
    return a;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}