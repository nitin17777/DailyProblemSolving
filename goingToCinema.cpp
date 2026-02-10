#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    int n = a.size();

    /*

    every person i will go only if atleast ai other people will go excluding himself

    */
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }

    int ans = 0, sum = 0;

    for (int k = 0; k <= n; k++)
    {
        if (cnt[k] == 0 && sum == k)
            ans++;

        sum += cnt[k];
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

        cout << solve(a) << endl;
    }
    return 0;
}