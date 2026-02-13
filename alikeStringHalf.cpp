#include <bits/stdc++.h>
using namespace std;

bool halvesAreAlike(string s)
{
    int n = s.size();

    int w1 = 0, w2 = 0;

    set<char> st = {'a', 'e', 'i', 'o', 'u'};

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    for (int i = 0; i < n / 2; i++)
    {
        if (st.find(s[i]) != st.end())
            w1++;

        if (st.find(s[i + n / 2]) != st.end())
            w2++;
    }
    return w1 == w2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << (halvesAreAlike("book") ? "true" : "false") << endl;

    return 0;
}