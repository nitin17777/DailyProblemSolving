#include <iostream>
using namespace std;

int minCandies(int n)
{
    // give same candies to all

    // return highest multiple of 3 just greater than n
    if (n % 3 != 0)
    {
        int g = ((n / 3) + 1) * 3;
        return g - n;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        cout << minCandies(n) << endl;
    }

    return 0;
}
