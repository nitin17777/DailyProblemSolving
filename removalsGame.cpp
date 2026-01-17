#include <bits/stdc++.h>
using namespace std;

string solve(vector<int> &a, vector<int> &b)
{
    int n = a.size();

    /*
    Alice either chooses first or last element of her array and removes it
    Bob chooses either the first or the last element and do the same

    Game lasts for n-1 rounds

    IF x = y ->Bob wins, else alice wins

    Determine who will win
    */

    if (a == b)
        return "Bob";

    reverse(a.begin(), a.end());

    if (a == b)
        return "Bob";

    return "Alice";
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
        vector<int> b(n);

        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        cout << solve(a, b) << endl;
    }
    return 0;
}