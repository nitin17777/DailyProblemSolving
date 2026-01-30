#include <bits/stdc++.h>
using namespace std;

int minFlips(string target)
{
    int n = target.size();

    /*
    In one operation we can :
    Pick an index i and flip all bits in the inclusive range [i, n - 1]

    Return the min number of ops to make s equal to target

    Count the number of subparts
    */

    set<char> st(target.begin(), target.end());
    if (st.size() == 1)
    {
        if (target[0] == 1)
            return 1;
        else
            return 0;
    }

    // Now count how many different subparts are coming
    char curr = '0';
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (target[i] != curr)
        {
            cnt++;
            curr = target[i];
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << minFlips("10111") << endl;

    return 0;
}