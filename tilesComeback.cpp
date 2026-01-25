#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a, int k)
{
    int n = a.size();
    /*
    ith tile has color ci

    on jumping any number of tiles right form first tile, we can get a path of length p -> And length of this path  = number of tile we are on

    Determine if we can get a path of length p such that:
    It ends at tile with index n
    p is divisible by k
    Path is divided into blocks of exactly k lengths
    Tiles in each block have same color
    */

    vector<int> suffix(n, 0); // Denotes number of tiles having same color as last tile from that index to the end

    suffix[n - 1] = 1; // last tile matches itself

    // Building suffix now
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + (a[i] == a[n - 1]);
    }

    // Single block is valid in this case only
    if (suffix[0] >= k && a[0] == a[n - 1])
    {
        return true;
    }

    // Case 2 now :

    // Counting the appearances of 1st color tile
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[0])
            count++;

        // Checking until the point we have sufficient block 1 and block 2 colors
        if (count >= k && suffix[i + 1] >= k)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << (solve(a, k) ? "Yes" : "No") << endl;
    }
    return 0;
}