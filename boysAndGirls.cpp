#include <bits/stdc++.h>
using namespace std;

string solve(int n, int m)
{
    /*
    n boys and m girls are studying in class

    They should stand in line so that boys and girls alternate as much as possible

    Positions are indexed from left to right from 1 to n+m

    Help the childrens form the line correctly
    */

    string s = "";
    int common = min(n, m);

    // The greater one will start the pair
    while (common != 0)
    {
        if (n > m)
        {
            s += "BG";
        }
        else if (n < m)
        {
            s += "GB";
        }

        else
            s += "BG";

        common--;
    }

    if (n > m)
    {
        for (int i = 0; i < n - m; i++)
            s += 'B';
    }
    else if (n < m)
    {
        for (int i = 0; i < m - n; i++)
            s += 'G';
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, s;
    cin >> t >> s;

    cout << solve(t, s) << endl;

    return 0;
}