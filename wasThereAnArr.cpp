#include <bits/stdc++.h>
using namespace std;

bool solve(string &s)
{
    /*
    Equality characteristic = arr b where bi = 1,if both of a's neighbour are equal to ai

    0 otherwise

    We are given array b, we have to determine if any array a exists or not


    */

    // Not possible if bi-1 = bi+1 = same and bi = 0

    if (s.find("101") != string::npos)
        return false;

    return true;
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

        string s, x;

        for (int i = 0; i < n - 2; i++)
        {
            cin >> x;
            s += x;
        }
        cout << (solve(s) ? "Yes" : "No") << endl;
    }
    return 0;
}