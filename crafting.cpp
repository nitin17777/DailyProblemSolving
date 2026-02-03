#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a, vector<int> &b)
{
    int n = a.size();

    /*

    In one operation: After selecting i : update ai = ai + 1 and aj = aj-1 for all j where j != i

    To successfully craft an artifact we must have atleast bi units of material i

    Determine if it possible to craft the artifact by performing the operation any numnber of times


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

        vector<int> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        cout << solve(a, b) << endl;
    }
    return 0;
}