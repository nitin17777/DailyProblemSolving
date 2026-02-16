#include <bits/stdc++.h>
using namespace std;

bool solve(string &s, string &t)
{
    reverse(t.begin(), t.end());

    return s == t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n, m;
    cin >> n >> m;

    cout << (solve(n, m) ? "YES" : "NO") << endl;

    return 0;
}