#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int or)
{

    // code is such that: OR of elements of code  = x=> greatest element should be x

    // and MEX = n, among all such arrays

    // create such code with given n and x

    // greates element = OR -1

    vector<int> ans(n);

    return ans;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, x;

        cin >> n >> x;
        vector<int> ans = solve(n, x);

        for (auto &x : ans)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}
