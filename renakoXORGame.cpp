#include <bits/stdc++.h>
using namespace std;

int winner(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    /*
    A->Odd turns
    M->Even turns

    In ith turn, player may choose to swap(ai,bi) or pass
    And the index swapped must match the turn number

    A-> Can swap only odd indices
    M -> Can swap only even indices



    Final Score: Score of both arrays

    And player with higher score will win else tie
    */

    int xra = accumulate(a.begin(), a.end(), 0, [](int x, int y)
                         { return x ^ y; });

    int xrb = accumulate(b.begin(), b.end(), 0, [](int x, int y)
                         { return x ^ y; });

    if (xra ^ xrb == 0)
        return 0; // Tie

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            if ((i + 1) % 2 != 0)
                return 1; // A

            else
                return 2; // M
        }
    }
    return 0;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int ans = winner(a, b);

        if (ans == 1)
            cout << "Ajisai" << endl;

        else if (ans == 2)
            cout << "Mai" << endl;

        else
            cout << "Tie" << endl;
    }

    return 0;
}
