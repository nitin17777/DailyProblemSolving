#include <bits/stdc++.h>
using namespace std;

int mini(string s)
{
    int n = s.size();

    /*
    Initially the finger is on button 0
    We have 2 choices:
    1->Press the button your finger is currently on and this will press the character that is on the button

    2->Move tour finger to other button ,if on 0 move to 1 and vice versa


    Additionally we may reverse atmost one substring of s

    Cost = operations required to type the string

    return the minimum possible cost

    ALgo:
    We have to click the button n times + number of times we need to switch our finger -> No. of times two distinct elements are there
    */

    s = '0' + s;

    // Counting switches

    int ans = 0;

    char curr = s[0];
    for (int i = 1; i <= n; i++)
    {
        if (curr != s[i])
            ans++;
        curr = s[i];
    }

    // we can reduce atmost 2 switches

    int res = 0;
    if (ans >= 3)
    {
        res = n + ans - 2;
    }

    else if (ans == 2)
    {
        res = n + ans - 1;
    }

    else
        res = ans + n;

    return res;
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

        string s;
        cin >> s;

        cout << mini(s) << endl;
    }

    return 0;
}