#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int> &a)
{
    /*
    1-> Deal 1 damage to any monster alive
    2-> Deal 1 damage to all alive monster and if a monster dies due to this, repaeat it

    Spell 2 can be used just once

    Return the min number of times spell 1 can be used
    */

    // Use it when atleast one monster has 1 hp remaining

    // use spell 1 until we have proper counting from 1 to ...

    // check which count we have ,and find the changes required to get it

    sort(a.begin(), a.end());
    int n = a.size();

    int hp = 1;
    ll ans = a[0] - 1;

    for (int i = 1; i < n; i++)
    {
        hp = min(hp + 1, a[i]);
        ans += a[i] - hp;
    }
    return ans; // Wrong Approach idk why

    /* Tourist's Method

    int n = a.size();

    sort(a.begin(), a.end());
    vector<int> b(n);

    b[0] = 1;

    for (int i = 1; i < n; i++)
    {
        b[i] = min(b[i - 1] + 1, a[i]); // Finding the ideal differennce to make arrray without missing any number
    }

    ll ans = 0;
    // finding the difference bw ideal and the given one
    for (int i = 0; i < n; i++)
    {
        ans += a[i] - b[i];
    }
    return ans;*/
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