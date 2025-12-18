#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int x, int y)
{
    /*
    P1 + P2 => Winner + P3 => winner + P4...and so on, total of n-1 games are played and at last the winner of last game wins the game


    Each player has either won x games or y games in championship


    Find the winner


    therefore possible iff:

    min(x,y) = 0
    max(x,y)>1
    (n-1)%max(x,y) = 0;
    */
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, x, y;

    for (cin >> t; t--;)
    {
        cin >> n >> x >> y;
        if (x > y)
            swap(x, y);
        if (x || !y || (n - 1) % y)
        {
            cout << -1 << endl;
            continue;
        }
        for (int k = 2; k <= n; k += y)
        {
            for (int i = 1; i <= y; i++)
                cout << k << ' ';
        }
        cout << endl;
    }

    return 0;
}