#include <bits/stdc++.h>
using namespace std;

string solve(vector<int> &a)
{

    int n = a.size();
    /*

    Append the given query qi if the array remains beautiful after appending, otherwise do nothing

    And after each query report whether appended or not

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

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a) << endl;
    }
    return 0;
}