#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int maxi = max(a, b);

    int num = 7 - maxi;
    int den = 6;

    int g = __gcd(num, den);

    num /= g;
    den /= g;

    cout << num << "/" << den << endl;

    return 0;
}