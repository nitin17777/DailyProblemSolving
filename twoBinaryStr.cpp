#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b)
{
    int n = a.size();

    /*
    In one operation: In any string , between any same type of bits,convert bw elements to them

    Determine if we can make both the strings equal by doing any number of this operation

    */

    for (int i = 0; i < n; i++)
    {
        if (((a[i] == b[i]) && (a[i] == '0')) && ((a[i + 1] == b[i + 1]) && a[i + 1] == '1'))
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string m, n;
        cin >> m >> n;

        cout << (solve(m, n) ? "Yes" : "No") << endl;
    }
    return 0;
}