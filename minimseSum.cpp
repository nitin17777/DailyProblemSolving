#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    int n = a.size();

    // We can select any 2 indices and assignn ai = ai + aj and set aj = 0, and this can be done only once

    // Return the min value of min(a1) + min(a1,a2) +....
    return min(2 * a[0], a[0] + a[1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a) << endl;
    }
    return 0;
}