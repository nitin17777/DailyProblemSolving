#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, int k)
{
    /*
    We can perform this operation any number itmes

    Choose number x from set such that there are atleast k multiples of x in s and then remove x from s
    */

    // Integer x can be  removed iff x *k <= r --> x <= r/k---->
    // So valid range = (l, r/k)

    int ans = max((r / k) - l + 1, 0);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        cout << solve(l, r, k) << endl;
    }
    return 0;
}