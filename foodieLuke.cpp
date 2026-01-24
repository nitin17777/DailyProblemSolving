#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int x)
{

    int n = a.size();
    /*

    Luke can eat the pile if and only if |v-ai| < x

    He can choose any

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
        int n, x;
        cin >> n >> x;

        vector<int> a(n);

        cout << solve(a, x) << endl;
    }
    return 0;
}