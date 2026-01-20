#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{

    int n = a.size();
    int maxi = *max_element(a.begin(), a.end());
    int reds = (n + 1) / 2;

    int ans = maxi + reds;

    if (n % 2 == 0)
        return ans;

    bool ok = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxi && i % 2 == 0)
        {
            ok = true;
            break;
        }
    }

    if (ok)
        return ans;

    return ans - 1;
}

/*
int solve(vector<int> &a)
{
    int n = a.size();

    /*
    No 2 adjacent elements can be red

    Return the max value of red element and number of red elements


    vector<int> x, y;

    int s1 = 0, s2 = 0;


    // for (int i = 0; i < n; i += 2)
    // {
    // }

    // for (int i = 1; i < n; i += 2)
    //     y.push_back(a[i]);

    // int maxx = *max_element(x.begin(), x.end());

    // int score1 = maxx + x.size();

    // int maxy = *max_element(y.begin(), y.end());
    // int score2 = maxy + y.size();

    // return max(score1, score2);
}*/

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
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << solve(a) << endl;
    }
    return 0;
}