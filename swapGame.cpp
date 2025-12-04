#include <bits/stdc++.h>
using namespace std;

int winner(vector<int> &a)
{
    /*
    If ai == 0, the player looses the game
    Player chooses some i with 2 <= i <= n,then player decreases the value of a1 by 1 and swaps a1 by ai

    Determine the winner of the game if both play optimally

    Alice will play first

    ALgo: Player who first faces he current global min is forced to decrease the minimum repeatedly and will create zero eventually

    */

    int minEle = *min_element(a.begin(), a.end());

    if (a[0] > minEle) // means bob will face the minElement
        return 1;

    else // in case alice will face the min
        return 2;
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

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        if (winner(a) == 1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}