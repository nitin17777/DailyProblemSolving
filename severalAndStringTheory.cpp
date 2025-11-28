#include <bits/stdc++.h>
using namespace std;

// Universal iff r is lexicographically smaller than s
bool isPos(string s)
{
    string r = s;
    reverse(r.begin(), r.end());

    return s < r;
}

/*
bool isPos(int k, string s)
{

    /*
    Univesal iff s is lexicogrpahically smaller than reversal of s

    //we can take any 2 indices and swap s[i],s[j]

    we have to determine if we can make s univesal by using this above op at most k times

    set<char> st(s.begin(), s.end());
    if (st.size() == 1)
        return false;

    int n = s.size();
    if (n == 1)
        return false;
    ;

    if (s[0] > s[n - 1])
        return true;

    if ((s[0] < s[n - 1]) && k == 0)
        return false;

    int l = 0, r = n - 1;

    while (l <= r)
    {
        if (s[l] < s[r])
        {
            if (k == 0)
                return false;
            else
                k--;
        }
        l++;
        r--;
    }
    return true;

    // while (k > 0)
    // {
    //     if (s[l] < s[r])
    //         k--;

    //     l++;
    //     r--;
    // }
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        set<char> st(s.begin(), s.end());
        if (st.size() == 1)
        {
            cout << "No\n";
            continue;
        }

        // If already universal
        if (isPos(s))
        {
            cout << "Yes\n";
            continue;
        }

        if (k >= 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}