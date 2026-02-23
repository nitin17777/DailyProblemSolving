#include <bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k)
{
    int n = s.size();

    if (n < (1 << k) + k - 1)
        return false;

    // Return true if evergy binary code of length k is a substring of s,else return false;

    // Brute force: Form all combos of 0 and 1 of given lenght k and check if they are present in given string s or not

    // check if there exists 2^k substrings of 0 and 1 in given string

    set<string> st;

    // form all subtrings ->insert it into set and check if set size == 2^k

    for (int i = 0; i + k <= n; i++)
    {
        st.insert(s.substr(i, k));
    }

    return st.size() == int(pow(2, k));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << (hasAllCodes("00110110", 2) ? "True" : "False") << endl;

    return 0;
}