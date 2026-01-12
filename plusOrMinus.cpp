#include <bits/stdc++.h>
using namespace std;

char solve(int a, int b, int c)
{
    /*
    a+b = c;
    a-b = c;

    */

    if (a + b == c)
        return '+';
    else
        return '-';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        cout << solve(a, b, c) << endl;
    }
    return 0;
}