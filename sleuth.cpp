#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    // last letter vowel -> Yes, else no

    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    int i = s.size() - 1;

    while (i >= 0 && !isalpha(s[i]))
        i--;

    if (i >= 0)
    {

        char ch = tolower((unsigned char)s[i]);
        if (vowels.count(ch))
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }

    return 0;
}