#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, l, v1, v2;
    cin >> d >> l >> v1 >> v2;
    // Luke dies as soon as distance bw presses < d

    // Determine how long can he survive

    long double ans = (long double)(l - d) / (v1 + v2);

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}