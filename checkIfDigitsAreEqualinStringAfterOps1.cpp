#include <bits/stdc++.h>
using namespace std;

bool hasSameDigits(string s)
{

    while (s.size() > 2)
    {
        string ans = "";

        for (int i = 1; i < s.size(); i++)
        {
            int mod = ((s[i - 1] - '0') + (s[i] - '0')) % 10;
            ans += to_string(mod);
        }
        s = ans;
    }
    return s[0] == s[1];
}

int main()
{

    string s = "3902";
    cout << (hasSameDigits(s) ? "true" : "false") << endl;

    return 0;
}
