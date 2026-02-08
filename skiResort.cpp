#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(ll n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    return n * fact(n - 1);
}

int solve(vector<int> &a, int k, int q)
{
    /*

    He will go for atleast k days
    On ith day, temperature would be ai degrees

    Can go only if temperature < q

    Determine the lenber of ways to choose vacation dates at the resort


    */

    // Count lenber of consecutive days, if consecutive days >= k , then add their factorial
    int n = a.size();

    // //Replacing every valid day with 1 and invalid day with 0

    // for(int i = 0;i<n;i++)
    // {
    //     if(a[i]>k)a[i] = 0;
    //     else a[i] = 1;
    // }

    int l = 0;
    int ans = 0;
    int len = 0;

    for (int r = 0; r < n; r++)
    {
        if (a[r] <= q)
            len++;

        else
        {
            if (len >= k)
            {
                ans += (len - k + 1) * (len - k + 2);
            }
            len = 0;
        }
    }

    if (len >= k)
    {
        ans += (len - k + 1) * (len - k + 2);
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
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a, k, q) << endl;
    }
    return 0;
}