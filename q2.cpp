#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    int s = accumulate(a.begin(), a.end(), 0);
    int n = a.size() + 1;

    int su = (n * (n + 1) / 2);

    return su - s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {1, 2, 3, 5};

    cout << solve(a) << endl;

    return 0;
}