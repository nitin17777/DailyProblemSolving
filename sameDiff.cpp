#include <bits/stdc++.h>
using namespace std;

int mini(string &s)
{

    int n = s.size();

    /*
    we can change s[i] to s[i+1] in one operation

    Find min ops to make all elements of the given string same

    */
    int ch = s[n - 1];
    int cnt = count(s.begin(), s.end(), ch);

    return n - cnt;
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

        s.erase(remove(s.begin(), s.end(), '.'), s.end());

        cout << mini(s) << endl;
    }
    return 0;
}
