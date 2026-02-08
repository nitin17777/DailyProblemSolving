#include <bits/stdc++.h>
using namespace std;

string solve(string &a, string &b)
{
    /*

    Astersik minor if number of asterisks in it are less than or equal to number of letters in it

    string s is said to be matched with template t if: We can replace each asterisk

    */

    // Bases cases : First and last letter checking first
    if (a[0] == b[0])
        return string(1, a[0]) + "*";

    if (a.back() == b.back())
    {
        return "*" + string(1, b.back());
    }

    for (int i = 0; i < b.size() - 1; i++)
    {
        string sub = "";
        sub += b[i];
        sub += b[i + 1];

        if (a.find(sub) != string::npos)
        {
            return "*" + sub + "*";
        }
    }
    return "";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;

        string ans = solve(a, b);

        if (ans.empty())
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
            cout << ans << endl;
        }
    }
    return 0;
}