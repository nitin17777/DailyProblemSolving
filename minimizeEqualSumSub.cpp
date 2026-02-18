#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    int n = a.size();

    // We have to fund the permutation q of length n that minimises the number of pairs (i,j) : sum(pi) = sum(qi)

    rotate(a.begin(), a.begin() + 1, a.end());

    return a;
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

        vector<int> ans = solve(a);
        for (auto &x : ans)
            cout << x << " ";

        cout << endl;
    }
    return 0;
}