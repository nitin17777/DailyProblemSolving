#include <bits/stdc++.h>
using namespace std;

// More mathematically optimised
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    int bRoute = 1;
    int bTime = INT_MAX;

    for (int k = 1; k <= n; k++)
    {
        int s, d;
        cin >> s >> d;

        int arrival = 0;

        if (s >= t)
            arrival = s;

        else
        {
            int jumps = (t - s + d - 1) / d;
            arrival = s + jumps * d;
        }

        if (arrival < bTime)
        {
            bTime = arrival;
            bRoute = k;
        }
    }
    cout << bRoute << endl;
}

/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    // Will go to the station at time t and there are n bus routes which stops at the station

    // Determine the best bus route for him

    int ans = 0;
    vector<int> a;

    for (int k = 1; k <= n; k++)
    {
        int s, d;
        cin >> s >> d;

        while (s < t)
        {
            s += d;
        }
        a.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] - t;
    }

    // Now return the index + 1 of least value

    int mini = a[0];
    int idx = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < mini)
        {
            mini = a[i];
            idx = i;
        }
    }
    cout << idx + 1 << endl;

    return 0;
}*/