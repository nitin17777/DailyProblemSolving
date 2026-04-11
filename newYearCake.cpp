#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (a < b) swap(a, b);

        long long x = 0, y = 0;
        long long ans = 0;
        long long cur = 1;

        while (true) {
            long long newX = y + cur;
            long long newY = x;

            if (newX <= a && newY <= b) {
                ans++;
                x = newX;
                y = newY;
                cur *= 2;
            } else {
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}