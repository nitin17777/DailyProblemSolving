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

    And player with higher score will win else ti

    Difference in this hard version is that value of each element can eb amnything >= 1
    */

    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= a[i];
        xr ^= b[i];
    }

    if (xr == 0)
        return 0; // Tie

    // Finding most significant bit
    int bit = 0;

    for (int i = 0; i < 20; i++)
    {
        if (xr & (1 << i)) //
            bit = i;
    }
    //"bit" will be highest set bit in xr

    int idx = -1;

    // Now finding the largest index where this bit differs:
    for (int i = 0; i < n; i++)
    {
        if ((a[i] ^ b[i]) & (1 << bit))
            idx = i;
    }

    if ((idx & 1)) // if index is odd,Mai mins
        return 2;

    return 1; // else ajisai wins
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
