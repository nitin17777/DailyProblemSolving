#include <bits/stdc++.h>
using namespace std;

bool is(string &s, int pos)
{
    /*

    She wants to make that string more beautiful by performing q operations

    i,v -> ith character of the string is assigned the value v

    So check if after each query whether the substring "1100" is present in her string or not
    */

    if (pos < 0 || pos + 3 >= s.size())
        return false;

    return s[pos] == '1' && s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();
        int cnt = 0;

        // Counting the number of initially present "1100"
        for (int i = 0; i + 3 < n; i++)
        {
            if (is(s, i))
                cnt++;
        }

        int q;
        cin >> q;
        while (q--)
        {
            int i;
            char v;
            cin >> i >> v;
            i--; // to convert to 0 based indexing

            // removing any "1100" present nearby
            for (int pos = i - 3; pos <= i; pos++)
            {
                if (is(s, pos))
                    cnt--;
            }

            s[i] = v;

            // Adding back
            for (int pos = i - 3; pos <= i; pos++)
            {
                if (is(s, pos))
                    cnt++;
            }
            cout << (cnt > 0 ? "Yes\n" : "No\n");
        }
    }
    return 0;
}