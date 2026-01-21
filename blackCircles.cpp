#include <bits/stdc++.h>
using namespace std;

bool solve(double xs, double ys, double xt, double yt, const vector<pair<double, double>> &circles)
{
    /*
    ith circle is centered at (xi,yi)
    Their radius increase at rate of 1 unit per second

    We have to reach point (xt,yt) without touchiing the circumference of the circle

    Determine if this is possible

    */

    double yourTime = (xs - xt) * (xs - xt) + (ys - yt) * (ys - yt);

    for (const auto &c : circles)
    {
        double cirTime = (c.first - xt) * (c.first - xt) + (c.second - yt) * (c.second - yt);

        if (cirTime <= yourTime)
            return false;
    }
    return true;
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

        vector<pair<double, double>> circles(n);
        for (int i = 0; i < n; i++)
        {
            cin >> circles[i].first >> circles[i].second;
        }

        double xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;

        cout << (solve(xs, ys, xt, yt, circles) ? "YES" : "NO") << endl;
    }
    return 0;
}