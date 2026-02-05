#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &p, int d)
{
    int n = p.size();

    // ith candidate has powe pi
    // One player can join only one team atmost

    // Win if sum of all powers of team > d

    // Determine the max number of wins he can achieve

    sort(p.rbegin(), p.rend());
    int rem = n;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int need = d / p[i] + 1; // for ceil(d/p[i])

        if (need <= rem)
        {
            cnt++;
            rem -= need;
        }
        else
            break;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for (auto &x : p)
        cin >> x;

    cout << solve(p, d) << endl;

    return 0;
}