#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    /*
    array x is beautiful if there exists and array y such that elements of y are distinct

    And product fo xi and yi is smae for all i


    Return the max size of subsequence of array a that is beautiful

    */

    int n = a.size();

    set<int> st(a.begin(), a.end());
    return st.size();
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