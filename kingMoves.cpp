#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    char c = s[0];
    char d = s[1];

    int cnt = 0;

    if (c == 'a' || c == 'h')
        cnt++;
    if (d == '1' || d == '8')
        cnt++;
    if (cnt == 0)
        return 8;

    if (cnt == 1)
        return 5;

    if (cnt == 2)
        return 3;

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}