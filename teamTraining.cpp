#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int x)
{
    /*
    Skill of ith student is ai
    Strong if :  strength is at least x
    Strength  = no. of team members * min skill among team

    Return the max possible number of strong teams

    */

    int n = a.size();
    int ans = 0;

    sort(a.rbegin(), a.rend());

    for (int i = 0, cnt = 1; i < n; i++, cnt++)
    {
        if (a[i] * cnt >= x)
        {
            ans++;
            cnt = 0;
        }
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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a, x) << endl;
    }
    return 0;
}