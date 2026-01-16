#include <bits/stdc++.h>
using namespace std;

int solve(int l, int a, int b)
{
    /*
    Prize wheel is divided into l sections numbered from 0 to l-1 sections

    initially prize pointer is at section a and moves exactly b section forward: Pointer moves from section a to (a+b)mod l then (a+2b)mod l and so on


    Determine the max prize we can get

    */

    vector<bool> visited(l, false);
    int ans = 0;

    int curr = a;

    while (!visited[curr])
    {
        visited[curr] = true;
        ans = max(ans, curr);

        curr = (curr + b) % l;
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
        int l, a, b;
        cin >> l >> a >> b;
        cout << solve(l, a, b) << endl;
    }
    return 0;
}