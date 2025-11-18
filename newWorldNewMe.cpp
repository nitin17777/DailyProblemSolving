#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int k, int p)
{

    if (k == 0)
        return 0; // no operation is required in this  case

    if (n * p < abs(k))
        return -1; // impossible

    if (n == abs(k) && abs(k) == p)
        return 1;

    int div = abs(k) / p;

    if (abs(k) % p != 0)
        return div + 1;

    else
        return div;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, p;
        cin >> n >> k >> p;

        cout << solve(n, k, p) << endl;
    }
    return 0;
}
