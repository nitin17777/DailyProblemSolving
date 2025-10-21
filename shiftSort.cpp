#include <bits/stdc++.h>
using namespace std;

int minNum(string s)
{
    // choose 3 indices, 1<i<j<k<n, right shift or left shift the values cyclically

    // we have to determine number of operations required to sort the given binary string
    int count = 0;

    // in sorted array,first c0 positions are filled with 0 and n-c0 positions are filled with 1 only

    // so if in original array 1 comes under c0 and vice versa , they need to be changed

    string p = s;
    sort(p.begin(), p.end());

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != p[i])
            count++;
    }
    return count / 2; // since each operation will fix 2 misplaced bits
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;
        cout << minNum(s) << endl;
    }
    return 0;
}
