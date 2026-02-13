#include <bits/stdc++.h>
using namespace std;

int solve(string &s)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.size();

    for (int i = 0; i < n;)
    {
        if (s[i] == '.')
        {
            cout << 0;
            i++;
        }

        else
        {
            if (s[i + 1] == '.')
                cout << 1;

            else
                cout << 2;

            i += 2;
        }
    }
    return 0;
}