#include <bits/stdc++.h>
using namespace std;

int years(vector<int> &d, int a, int b)
{

    int years = 0;

    for (int i = a - 1; i < b - 1; i++)
    {
        years += d[i];
    }
    return years;

    // 1 is the lowest rank and n is the highest rank
    // di years to rise from rank to i+1 rank

    // vasya reached new rank a , but he dreams of holding rank of b

    // no. of years required for vasya to rise from rank a to rank b
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> d[i];
    }

    int a, b;
    cin >> a >> b;

    cout << years(d, a, b) << endl;

    return 0;
}