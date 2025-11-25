#include <bits/stdc++.h>
using namespace std;

bool isPos(string a, string b)
{

    /*

    Choose index : 2<=i<=n

    In one operation : swap(ai, bi-1)
                     : swap(bi,ai-1)



    */

    int n = a.size();
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
                }
    }

    for (int i = 0; i < n; i++)
    {
        if (i & 1 == 0)
        {
            cnt2 += a[i];
        }
        else
            cnt2 += b[i];
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        cout << (isPos(a, b) ? "Yes" : "No") << endl;
    }
    return 0;
}
