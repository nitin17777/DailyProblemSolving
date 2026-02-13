#include <bits/stdc++.h>
using namespace std;

vector<string> findWords(vector<string> &words)
{

    vector<int> row(26);
    string r1 = "qwertyuiop";
    string r2 = "asdfghjkl";
    string r3 = "zxcvbnm";

    // Marking all letters according to the row in which they are
    for (char c : r1)
        row[c - 'a'] = 1;
    for (char c : r2)
        row[c - 'a'] = 2;
    for (char c : r3)
        row[c - 'a'] = 3;

    vector<string> ans;

    for (string word : words)
    {
        string t = word;
        // Transform applies the last written operation inn the given range
        transform(t.begin(), t.end(), t.begin(), ::tolower);

        int r = row[t[0] - 'a'];
        bool ok = true;

        for (char c : t)
        {
            if (row[c - 'a'] != r)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            ans.push_back(word);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};

    vector<string> ans = findWords(words);
    for (auto &x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}