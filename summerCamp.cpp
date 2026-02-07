#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll digits = 1;
    ll count = 9;
    ll start = 1;

    while (n > digits * count)
    {
        n -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }

    ll num = start + (n - 1) / digits;

    string s = to_string(num);

    cout << s[(n - 1) % digits] << endl;

    return 0;
}