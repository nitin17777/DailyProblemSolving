#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int n = s.size();

    // We can replace any char with 0,2,5,6 in one operation

    // Return the min number of ops required to make it a new year string

    // Just check if 2025 is there or not:
    // If present -> 1, else 0

    size_t pos5 = s.find("2025");

    size_t pos6 = s.find("2026");

    if (pos6 != string::npos)
        return 0;

    if (pos5 != string::npos)
        return 1;
    else
        return 0;
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
        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
    return 0;
}