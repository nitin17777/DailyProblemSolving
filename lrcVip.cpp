#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{

    int n = a.size();

    /*
    Return to which of the sequences aith element belongs: either 1 or 2

    Groups are divided such that gcd(B Group) != gcd(c Group)

    */
    set<int> st(a.begin(), a.end());

    if (st.size() == 1)
        return {};

    vector<int> ans;
    int maxi = *max_element(a.begin(), a.end());

    for (auto &v : a)
    {
        if (v == maxi)
            ans.push_back(2);

        else
            ans.push_back(1);
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
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        vector<int> ans = solve(a);

        if (ans.size() >= 1)
        {
            cout << "Yes" << endl;
            for (auto &an : ans)
                cout << an << " ";

            cout << endl;
        }

        else
            cout << "No" << endl;
    }
    return 0;
}