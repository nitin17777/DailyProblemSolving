#include <bits/stdc++.h>
using namespace std;

bool tournament(int n, int j, int k, vector<int> &strength)
{

    //
    // while more than k players remain, two players are chosen at random and the player with lower strength is eliminated.And if both players have same strength one of them is ranodmly eliminated

    // we have to determine if there is any way for player 'j' to be one of the last 'k'remaining players

    int sj = strength[j - 1];

    int stronger = 0;

    if (k > 1)
        return true;

    if (k == 1)
    {

        for (int i = 0; i < strength.size(); i++)
        {
            if (strength[i] > sj)
                stronger++;
        }
        return stronger < k;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, j, k;

        cin >> n >> j >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (tournament(n, j, k, a))
        {
            cout << "Yes" << endl;
        }

        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
