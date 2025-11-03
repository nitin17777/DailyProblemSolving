#include <bits/stdc++.h>
using namespace std;

bool isPossible(string s)
{
    // Robots can destroy one opening and one closing bracket only

    // Determine if such two brackets are possible that s is no longer balanced bracket sequence
    int balance = 0;
    int n = s.size();
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return true; // This refers to the case when  at any point excessive ')' came before
    }

    if (balance != 0)
        return true;

    else
        return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        cout << ((isPossible(s)) ? "Yes" : "No") << endl;
    }

    return 0;
}
