#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n)
{
    /*
    In this problem, MEX = smallest x which doesn't occur in collection c
    Primality of an array a1,a2...an is defined as number of pairs (l,r) : 1 < l < r < n and MEX(al, ... , ar) is a prime number


    Primality -> Aise kitne (l,r) ke pair honge jinke andr elemnents ka MEX prime hoga
    Now find the permutation with max possible primality among all permutations of 1 to n


    */

    if (n == 1)
        return {1};
    if (n == 2)
        return {1, 2};

    int c = 4;
    vector<int> ans(n, 0);
    ans[0] = 2, ans[n / 2] = 1, ans[n - 1] = 3;

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 0)
            ans[i] = c++;
    }
    return ans;
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

        vector<int> ans = solve(n);

        for (auto &an : ans)
            cout << an << " ";

        cout << endl;
    }
    return 0;
}