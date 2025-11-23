#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(string s, ll x, ll y)
{

    /*

    Initially only cell (0,0) is black

    s[i] == 4 => if it is orthogonally adjacent to black cell , it becomes full black

    s[i] == 8 => if it is orthogonally or DIAGONALLY adjacent to black cell , it becomes full black


    Check if cell (x,y) black at the end of the process



    IF 8 is there,Square growing

    If 4 is there, a diamond is growing

    So final region would be : Square from 8 steps + Diamods from 4 steps


    */

    ll n = s.size();

    int cnt4 = 0, cnt8 = 0;

    for (auto x : s)
    {
        if (x == '4')
            cnt4++;
        else
            cnt8++;
    }

    // We can reduce |x|by cnt8 and |y| by cnt8 but not below 0

    // now we are left with distnace needed to cover with 4cnt(diamond)
    ll xx = max((ll)0, abs(x) - cnt8);
    ll yy = max((ll)0, abs(y) - cnt8);

    return (xx + yy) <= cnt4; // True if sufficient else false;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, x, y;
        string s;

        cin >> n >> x >> y >> s;

        cout << (solve(s, x, y) ? "Yes" : "No") << endl;
    }
    return 0;
}
