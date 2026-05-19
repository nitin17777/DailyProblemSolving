#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int n, m, k;
    cin >> n >> m >> k;

    int res = 1e9;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        if (a != 0 && a <= k) {
            res = min(res, abs(i - m));
        }
    }

    cout << 10 * res;

    return 0;
}
