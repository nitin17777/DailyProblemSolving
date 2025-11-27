#include <bits/stdc++.h>
using namespace std;

int moves(int n, vector<int> &a, int q)
{

    /*
    In each move david goes to an adjacent cell or stays at the same cell and teachers do the same



    */
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, qa;
        cin >> n >> m >> qa;

        vector<int> a(m);
        for (auto &x : a)
            cin >> x;

        int q;
        cin >> q;

        cout << moves(n, a, q) << endl;
    }
    return 0;
}
