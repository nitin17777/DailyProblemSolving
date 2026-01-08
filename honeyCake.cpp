#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int w, int h, int d, int n)
{
    /*
    They are going to host a party for n people including themselves

    Want to split honey cake into n equal pieces

    We have to determine the number of cuts to made along each dimensions w h and d, if possible else -1

    */

    vector<int> ans;

    int wp = __gcd(n, w);
    int nw = n / wp;

    int hp = __gcd(nw, h);
    int nh = nw / hp;

    int dp = __gcd(nh, d);
    int nd = nh / dp;

    if (nd != 1)
        return {-1};

    ans.push_back(wp - 1); // cuts required = part -1
    ans.push_back(hp - 1);
    ans.push_back(dp - 1);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h, d, n;
    cin >> w >> h >> d >> n;

    vector<int> ans = solve(w, h, d, n);
    for (auto &a : ans)
        cout << a << " ";

    cout << endl;

    return 0;
}