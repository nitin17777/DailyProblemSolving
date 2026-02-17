#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a)
{
    int n = a.size();

    // Determine if arrnagement that follows the given conditions exists?

    // Two adjcent cards can't have same color

    // On sorting , still adjacent digits must be of different colors

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // if both are consecutive, then it is impossible

        // Parity of current number  != parity of next index
        cnt += (a[i] % 2 != (i + 1) % 2);
    }
    // Since all correct or all needs to be flippedd

    return (cnt == 0 || cnt == n);
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

        cout << (solve(a) ? "Yes" : "No") << endl;
    }
    return 0;
}