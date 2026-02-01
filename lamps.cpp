#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>> &p)
{

    /*


    Each lamp can have one of these 3 states: Turned on, turned off, or broken

    Initially all lamps are turned off

    Lamps such that ai < x simultaneously break


    In one move we can select one lamp that is turned off and turn it on
    An we recieve bi points for turning lamp i on

    Find the max points we can get
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
        int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        for (auto &x : p)
            cin >> p;

        cout << solve(p) << endl;
    }
    return 0;
}