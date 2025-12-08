#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &c)
{
    /*
    ith cell is colored with color ai

    what color will be used for 10^18th cell

    little fiary counts number of distinct colors currenlty present on the ribbon denoted as ci, and then color the ith cell with ci


    */

    set<int> st(c.begin(), c.end());

    int sz = st.size();

    // check the just greater element than sz present in given array
    sort(c.begin(), c.end());

    for (auto &x : c)
    {
        if (x >= sz)
            return x;
    }
    return -1;
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
        vector<int> c(n);

        for (auto &x : c)
            cin >> x;

        cout << solve(c) << endl;
    }
    return 0;
}
