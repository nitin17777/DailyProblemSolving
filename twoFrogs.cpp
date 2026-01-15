#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int a, int b)
{
    /*
    In frog's turn it can either jump one space left or right


    Both must be in different pads

    And as soon as one frog fails to make a jump, it loses

    Determine if Alice can guarantee a win

    */

    if (n - a <= 1)
        return true;

    if (n - b >=)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        cout << (solve(n, a, b) ? "Yes" : "No") << endl;
    }
    return 0;
}