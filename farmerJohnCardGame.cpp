#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int m, vector<vector<int>> cards)
{
    /*
    Each cow should only be able to play 1 card per round

    He decides to determine a turn order determine by a permutation p of length n such that pith cow will be ith cow to place a card on top of the center pile in a round


    Means something like this happens:
    p1th cow places any card from their deck on top of the center pile
    and similary for other cows

    In order to place a card, the number of the card must be greater than the number of card on the top of the center pile

    If a cow is unable to do so, the game is considered to be lost

    If there is any possible permutation p such that all cows can empty their deck after playing m rounds of the game ,if so, return the permutation else return -1
    */

    vector<int> p(n, -1); // p[x] = index of cow whose min card is x

    for (int i = 0; i < n; i++)
    {
        // Sorting card of each row

        sort(cards[i].begin(), cards[i].end());

        // every succesive element of each row must differ by n

        for (int j = 1; j < m; j++)
        {
            if (cards[i][j] - cards[i][j - 1] != n)
                return {-1};
        }

        int minCard = cards[i][0];

        if (minCard < 0 || minCard >= n)
            return {-1};

        if (p[minCard] != -1)
            return {-1};

        p[minCard] = i;
    }

    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        vector<int> ans = solve(n, m, a);
        if (ans.size() == 1 && ans[0] == -1)
        {
            cout << -1 << endl;
            continue;
        }

        for (auto &x : ans)
            cout << x + 1 << " ";

        cout << endl;
    }
    return 0;
}