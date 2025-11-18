#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(string &s)
{

    ll n = s.size();

    ll a = count(s.begin(), s.end(), '-');
    ll b = n - a;

    if (a < 2 || b == 0)
        return 0;

    /*
    There are some '-' to left(lp) and right(ls) of '_' ,so total subsequences = lp *ls


    Also : lp + ls = a

    and to maximise lp*ls, we can put lp = ls = a/2

    Final total possible subsequece = a/2 * a/2 * b
    */

    ll lp = a / 2;
    ll ls = a - lp; // because we have odd digits also

    return lp * ls * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        cout << solve(s) << endl;
    }
    return 0;
}
