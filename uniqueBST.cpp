#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1; // base cases

    // computing number of BSTs for 2 to n nodes
    for (int nodes = 2; nodes <= n; nodes++)
    {
        // considering each node as root from 1 to nodes
        for (int root = 1; root <= nodes; root++)
        {
            // number of BSTs with this root = number of left  subtree * number of right subtree
            dp[nodes] += dp[root - 1] * dp[nodes - root];
        }
    }
    return dp[n];
}

int main()
{
    int ans = numTrees(3);
    cout << ans << endl;

    return 0;
}
