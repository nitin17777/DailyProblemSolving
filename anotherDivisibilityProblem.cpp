#include <bits/stdc++.h>
using namespace std;

// function to calculate 10^ digits correctly
long long power10(int digits)
{
    long long result = 1;
    for (int i = 0; i < digits; i++)
    {
        result *= 10;
    }
    return result;
}

int countDigits(long long n)
{
    return to_string(n).length();
}
long long solve(long long x)
{
    // alice has given an integer x to bob

    // to win the game, bob has to find y such that concatenation of x and y is divisble by x+y

    // we have to find the integer y, given that such y always exists

    // concatenation of x and y is divible by x+y

    // so w will be going with the strategy of y as multiple of x as this works more often due to concatenation in mathematics

    for (long long multiplier = 1; multiplier <= 9; multiplier++)
    {
        long long y = multiplier * x;

        if (y >= 1000000000)
            break;

        int digits = countDigits(y);

        long long concatenated = x * power10(digits) + y;

        if (concatenated % (x + y) == 0)
            return y;
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }

    return 0;
}