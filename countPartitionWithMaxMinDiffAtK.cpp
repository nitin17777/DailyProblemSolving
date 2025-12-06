#include <bits/stdc++.h>
using namespace std;
#define ll long long

int countPartitions(vector<int> &nums, int k)
{

    // partition nums into one or more segments such that in each segment difference bw it's max and and min element is at most k

    // Return total ways to partition

    // One case would be of all elements alone.

    const int MOD = 1000000007;
    int n = nums.size();

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    dequeue<int> maxdq, mindq;

    int l = 0;

    ll prefixSum = 0;
    vector<ll> pred(n + 1, 0);
    pref[0] = 1;

    for (int r = 0; r < n; r++)
    {
        int maxi =
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {9, 4, 1, 3, 7};

    cout << countPartitions(nums, 4) << endl;

    return 0;
}