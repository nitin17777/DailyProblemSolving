#include <bits/stdc++.h>
using namespace std;

string solve(vector<int> &l, vector<int> &r)
{

    /*


    for each i he can only remember li < wi< ri

    Eric believes that impression i is unique if and only if there exists an array w1, w2,..wn such that wi != wj


    Determine whether impression i is unique for every i independently

    */

    string s = "";
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

        vector<int> l(n), r(n);
        for (auto &x : l)
            cin >> x;
        for (auto &x : r)
            cin >> x;

        cout << solve(l, r) << endl;
    }

    return 0;
}