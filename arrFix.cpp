#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a)
{
    int n = a.size();

    // Move : Choose element -> Delete that element -> And place the numbers from which it was made in that exact location

    // Determine if we can make a sorted using the given operation  any number of times

    // Do this operation when the succeeding element is smaller than the previus one
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

        cout << (solve(a) ? "Yes" : "No") << endl;
    }
    return 0;
}