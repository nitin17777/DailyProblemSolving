#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{

    /*

    We can swap an element once at most on time

    */

    int n = a.size();
    int maxi = *max_element(a.begin(), a.end());

    return n * maxi;
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