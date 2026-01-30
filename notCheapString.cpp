#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

string solve(string s, int p)
{
    /*
    Price is the sum of indices of letters of string

    Remove the min numebr of letters so that it's price becomes less than or equal to p

    Return the longest possible string after doing the required task
    */

    int n = s.size();
    // Make the array of cost of per letter and remove the required cost

    int score = 0;
    for (auto c : s)
        score += c - 'a' + 1;

    // When our score is already less than p
    if (score <= p)
        return s;

    // In order to get the longest string, we should always look forward to delete the most expensive char

    string w(s);
    sort(w.rbegin(), w.rend());

    map<char, int> del;

    // Remove from right the most expensive char and then while we rewrite the string, just write till we have the count of that cahr available

    forn(i, w.length())
    {
        if (score > p)
        {
            del[w[i]]++;
            score -= w[i] - 'a' + 1;
        }
    }

    string ans = "";

    forn(i, s.length())
    {
        // If there is some deletion frequency skip writing that letter
        if (del[s[i]] > 0)
        {
            del[s[i]]--;
            continue;
        }

        ans += s[i];
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

        string s;
        cin >> s;

        int n;
        cin >> n;

        cout << solve(s, n) << endl;
    }
    return 0;
}