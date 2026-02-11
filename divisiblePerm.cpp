#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n)
{
    // permutation of size n such that abs(pi - pi+ 1) is divisible by i
    if (n == 1)
        return {0, 1};

    vector<int> p;
    unordered_set<int> used;
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

        vector<int> p = solve(n);
        for (int i = 1; i <= n; i++)
            cout << p[i] << " ";

        cout << endl;
    }
    return 0;
}