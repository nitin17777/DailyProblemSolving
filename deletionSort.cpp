#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    // at each turn if a is non decreasing the game ends

    // Else choose any number and remove it from the array

    // Determine the min possible elements that can be remaining in the array as the game ends

    if (is_sorted(a.begin(), a.end()))
        return a.size();
    else
        return 1;
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