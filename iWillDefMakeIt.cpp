#include <bits/stdc++.h>
using namespace std;

bool isPossible(int k, vector<int> &h)
{
    /*
    At time 0, we are on tower heights[k]
    Water level rises by 1 unit each second
    //if water level  > height of tower, you perish

    We can jump from tower i to tower j in |hi - hj|seconds
    And teleportation can start the moment we just arrive at tower j


    Goal is to reach any tower with max height before water covers me


    */
    int n = h.size();

    int curr = h[k - 1];
    int dist = h[k - 1]; // tells how many seconds we can survive

    sort(h.begin(), h.end());

    bool ans = true;

    for (int i = 0; i < n; i++)
    {
        if (h[i] < curr) // skip if smaller
            continue;

        if (h[i] - curr > dist) // if gap is grrater than the availability
            ans = false;

        curr = h[i];
    }
    if (ans)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> h(n);
        for (auto &x : h)
            cin >> x;

        cout << (isPossible(k, h) ? "Yes" : "No") << endl;
    }
    return 0;
}
