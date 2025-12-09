#include <bits/stdc++.h>
using namespace std;
#define ll long long

const long long MOD = 1000000007LL;

int specialTriplets(vector<int> &nums)
{
    int n = nums.size();

    /*
    1<i<j<k<n

    nums[i] = nums[j]*2
    nums[k] = nums[j] *2

    So:  nums[j] = (nums[i] + nums[j]) / 4

    Return the total numebr of special triplets in the array

    */

    //     int cnt = 0;
    //    for(int i=0; i<n; i++)
    //    {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             int k = 4*nums[j] - nums[i];

    //         }
    //    }

    unordered_map<ll, ll> lf, rf;
    // lf[x] stores how many time x has appeared before index j
    // rf[x] stores how many time x has appeared after index j

    vector<ll> l(n, 0), r(n, 0);
    // l[j] -> number of valid i<j : nums[i] = 2* nums[j];
    // r[j] -> number of Valid j<k : nums[k] = 2* nums[j];

    // Pass 1: Left to Right => for each j counting how many previous i exist such that nums[i] * 2 = nums[j]
    for (int j = 0; j < n; j++)
    {
        ll target = 2LL * nums[j];

        if (lf.count(target)) // if this target has appeared before, then those many i's are valid
        {
            l[j] = lf[target];
        }

        // now include nums[j] in our frequency map for future use by other j's
        lf[nums[j]]++;
    }

    // Pass 2: Right to Left : For each j counting how many k's right to j satisfies: 2*nums[k] = nums[j]
    for (int j = n - 1; j >= 0; j--)
    {
        ll target = 2LL * nums[j];

        if (rf.count(target))
        {
            r[j] = rf[target];
        }

        rf[nums[j]]++; // Now including nums[j] for future use
    }

    ll ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans = (ans + (l[j] * r[j]) % MOD) % MOD;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {6, 3, 6};
    cout << specialTriplets(nums) << endl;

    return 0;
}