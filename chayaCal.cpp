#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<int> &a)
{
    int n = a.size();

    // ith sign occurs every ai years

    // for apocalypse : Signs must occur sequentially

    // In which year will all n signs will occur

    // If ith sign occured in year x, tribe waits for occurence of (i+1)th sign starting from year x+1

    // For each sign find the first multiple of a[i] strictly greater than the previous sign's year

    ll sml = 0;
    for (int i = 0; i < n; i++)
    {
        sml = a[i] * ((sml / a[i]) + 1);
    }
    return sml;
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