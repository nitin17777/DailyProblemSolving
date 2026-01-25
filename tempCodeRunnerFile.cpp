#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int &x : p) cin >> x;

        for (int i = 0; i < n; i++) {
            int mx = p[i];
            int pos = -1;

            // find maximum in suffix
            for (int j = i + 1; j < n; j++) {
                if (p[j] > mx) {
                    mx = p[j];
                    pos = j;
                }
            }

            // if better element found, reverse and stop
            if (pos != -1) {
                reverse(p.begin() + i, p.begin() + pos + 1);
                break;
            }
        }

        for (int x : p) cout << x << " ";
        cout << "\n";
    }
}
