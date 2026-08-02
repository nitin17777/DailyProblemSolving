#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    int pos = 0;      // position 1 corresponds to index 0
    int jumps = 0;

    while (pos < n - 1) {
        int nxt = -1;

        // Find the farthest reachable lily
        for (int i = min(n - 1, pos + d); i > pos; i--) {
            if (s[i] == '1') {
                nxt = i;
                break;
            }
        }

        if (nxt == -1) {
            cout << -1 << '\n';
            return 0;
        }

        pos = nxt;
        jumps++;
    }

    cout << jumps << '\n';
    return 0;
}