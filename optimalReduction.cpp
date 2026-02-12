#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a)
{
    int n = a.size();

    // We can decrease elements in a substring by 1

    // f(a) = min number of operations needed to change array a into array of n zeroes

    // We have to check if for all permutations b of a , f(a) < f(b) is true
    int i = 1;
    // Increasing order from first (MOuntain start)
    while (i < n && a[i - 1] <= a[i])
        i++;

    int j = n - 1;
    // Decreasing order from last (mountain end)
    while (j > 0 && a[j - 1] >= a[j])
        j--;

    // Checking if increasing and decreasing part cann overlap or not
    return (i > j);
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