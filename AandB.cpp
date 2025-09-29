#include <bits/stdc++.h>
using namespace std;

int minOps(string s)
{
    // in one operation, we can choose a position i and swap (s i,s i+1)
    // min ops to ensure that all characters of type either a or b are located strictly together forming exactly one continuous block

    // we need to check if by swapping we an achieve
    int n = s.length();

    int counta = 0, countb = 0;

    for (char c : s)
    {
        if (c == 'a')
            counta++;
        else
            countb++;
    }

    // edge cases
    if (counta == 0 || countb == 0 || counta == n || countb == n)
        return 0;

    // trying to group all a's together

    int mincosta = INT_MAX;

    int currentb = 0;
    for (int i = 0; i < counta; i++)
    {
        if (s[i] == 'b')
            currentb++;
    }
    mincosta = currentb;

    // slide the window
    for (int i = counta; i < n; i++)
    {
        if (s[i - counta] == 'b')
        {
            currentb--;
        }
        if (s[i] == 'b')
            currentb++;

        mincosta = min(mincosta, currentb);
    }

    // trying to group all b's together
    int mincostb = INT_MAX;

    // counting a in first window of size countb
    int currenta = 0;
    for (int i = 0; i < countb; i++)
    {
        if (s[i] == 'a')
            currenta++;
    }

    mincostb = currenta;

    for (int i = countb; i < n; i++)
    {
        if (s[i - countb] == 'a')
            currenta--;
        if (s[i] == 'a')
            currenta++;

        mincostb = min(mincostb, currenta);
    }

    return min(mincostb, mincosta);
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

        cout << minOps(s) << endl;
    }

    return 0;
}
