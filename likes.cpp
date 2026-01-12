#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    int n = a.size();

    /*
    In ith second, ai either liked or removed the like
    If ai < 0 => Person -ai removed the like


    Determine the max and min number of likes that could be on the post for the momment
    */
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
        for (auot &x : a)
            cin >> x;

        vector<int> ans = solve(a);
        for (auto &an : ans)
            cout << an << " ";

        cout << endl;
    }
    return 0;
}