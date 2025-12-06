#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    // Return the smalllest possible integer after removing k digits from num

    int n = num.size();

    string st = "";

    // Remvoing the largest digit to make number smaller
    for (char c : num)
    {
        while (!st.empty() && st.back() > c && k > 0)
        {
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }

    // Remove from end if still there are digits needed to be removed
    while (k > 0 && !st.empty())
    {
        st.pop_back();
        k--;
    }

    // Removing leading zeroes
    int idx = 0;
    while (idx < st.size() && st[idx] == '0')
        idx++;

    // final answer
    string ans = st.substr(idx);

    return ans.empty() ? "0" : ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << removeKdigits("1432219", 3);

    return 0;
}