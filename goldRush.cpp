#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int m)
{

    /*

    In one operation, we can take any pile ad split it into two piles, so that one of the pilees have twice the nuggets as the other

    Determine if we can make exactly m gold nuggets using this

    Go to number n , divide it by three and get x , and then check if m == x or m==2x ,continue this for every number(x and 2x) and return yes if possible else return no
    */

    if (n == m)
        return true;
    if (n < m)
        return false;
    if (n % 3 != 0)
        return false;

    long long x = n / 3;

    return solve(x, m) || solve(2 * x, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << (solve(n, m) ? "Yes" : "No") << endl;
    }
    return 0;
}