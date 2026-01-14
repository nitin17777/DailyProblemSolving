#include <bits/stdc++.h>
using namespace std;

vector<string> solve(string &s)
{
    vector<string> ans;

    for (char ch : string("abcdefgh"))
    {
        if (ch != s[0])
        {
            string temp;
            temp += ch;
            temp += s[1];
            ans.push_back(temp);
        }
    }

    for (char ch : string("12345678"))
    {
        if (ch != s[1])
        {
            string temp;
            temp += s[0];
            temp += ch;
            ans.push_back(temp);
        }
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
        string n;
        cin >> n;

        vector<string> ans = solve(n);
        for (auto &an : ans)
            cout << an << endl;
    }
    return 0;
}