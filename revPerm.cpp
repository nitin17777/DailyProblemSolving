#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    /*
    Choose any segment and reverse the segment -> This operation can be done only once


    Return the lexicographically max permutation that can be obtained by doing this operation
    */

    // Get the n at first position firstly
    // int n = a.size();
    // for (int trgt = n; trgt >= 1; trgt--)
    // {
    //     int i = 0;
    //     while (a[i] != trgt)
    //         i++;

    //     if (i != 0)
    //     {
    //         reverse(a.begin(), a.begin() + i + 1);
    //         break;
    //     }
    // }
    // return a;
    int n = a.size();

    // We need to find the first index for which pi != n-i+1

    int i = 0;
    while (i < n && a[i] == n - i)
        i++;

    int num = n - i;

    int idx = 0;
    // Finding the index of this num
    for (int k = 0; k < n; k++)
    {
        if (a[k] == num)
        {
            idx = k;
            break;
        }
    }

    reverse(a.begin() + i, a.begin() + idx + 1);
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