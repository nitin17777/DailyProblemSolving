#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        vector<long long> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long total = 0;

        // Find initial total difference
        for(int i = 1; i < n; i++) {
            total += abs(a[i] - a[i - 1]);
        }

        long long ans = LLONG_MAX;

        // Remove first element
        ans = min(ans, total - abs(a[1] - a[0]));

        // Remove last element
        ans = min(ans, total - abs(a[n - 1] - a[n - 2]));

        // Remove middle elements
        for(int i = 1; i < n - 1; i++) {

            long long curr = total;

            curr -= abs(a[i] - a[i - 1]);
            curr -= abs(a[i + 1] - a[i]);

            curr += abs(a[i + 1] - a[i - 1]);

            ans = min(ans, curr);
        }

        cout << ans << endl;
    }

    return 0;
}