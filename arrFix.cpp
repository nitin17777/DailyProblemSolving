#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a)
{
    int n = a.size();

    // Move : Choose element -> Delete that element -> And place the numbers from which it was made in that exact location

    // Determine if we can make a sorted using the given operation  any number of times

    // Do this operation when the succeeding element is smaller than the previus one

    // break the number when next element is smaller

    vector<int> fin;
    fin.push_back(a[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > fin.back())
        {
            int d1 = a[i] / 10;
            int d2 = a[i] % 10;

            fin.push_back(d2);
            fin.push_back(d1);
        }

        else
        {
            fin.push_back(a[i]);
        }
    }

    return is_sorted(fin.rbegin(), fin.rend());
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