#include <bits/stdc++.h>
using namespace std;

bool solve(string &s)
{ /*

 Choose pairs such that :
 si = sj != *
 sk = *,  i< k < j
 If no such i,j exists -> game ends
 else si := * and sj := *

 Wins iff every char in s is equal to *
 */

    stack<int> st;
    for (auto&c : s)
    {
        if (st.size() && c == st.top())
            st.pop();
        else
            st.push(c);
    }
    return st.empty();
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

        cout << (solve(s) ? "YES" : "NO") << endl;
    }
    return 0;
}