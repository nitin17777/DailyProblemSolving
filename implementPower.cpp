#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    // we have to implement out own power function
    if (n == 0)
        return 1;
    if (x == 1.00000)
        return 1;

    long long exp = n;
    if (exp < 0)
    {
        x = 1 / x;
        exp = -exp;
    }

    double half = myPow(x, exp / 2);

    if (exp % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

int main()
{

    double x = 2.00000;
    int n = -2147483648;

    cout << myPow(x, n) << endl;
    return 0;
}
