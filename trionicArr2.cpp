#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long maxSumTrionic(vector<int> &nums)
{

    int n = nums.size();
}

/*
long long maxSumTrionic(vector<int> &nums)
{
    int n = nums.size();

    // Return the max of any trionic subarray

    vector<ll> incLeft(n);  // Increasing sub ending at i
    vector<ll> decLeft(n);  // Decreasing sun ending at i
    vector<ll> incRight(n); // Increasing sub starting at i

    // incLeft[i] = max sum of strictly increasing sum ending at index i

    incLeft[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        // Can extend if current element is greater
        if (nums[i] > nums[i - 1])
        {
            incLeft[i] = incLeft[i - 1] + nums[i];
        }

        else // Otherwise start a new increasing sub
        {
            incLeft[i] = nums[i];
        }
    }

    // Computing -> decLeft[i] = max sum of strictly decreasing sub ending at i

    decLeft[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        // Extend decreasing sequence in this case
        if (nums[i] < nums[i - 1])
        {
            decLeft[i] = nums[i] + decLeft[i - 1];
        }

        else
            decLeft[i] = nums[i]; // Otherwise start new decreasing sequence
    }

    // Computing -> incRight[i] = max sum of strictly increasing sub starting at index i

    incRight[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            incRight[i] = incRight[i + 1] + nums[i];
        }

        else
            incRight[i] = nums[i];
    }

    // Now trying every index as middle valley end

    /*
    ---------------------------------------------------------
    STEP 4: Try every index as middle valley end (q)
    ---------------------------------------------------------

    Structure we want:

    Increasing   →   Decreasing   →   Increasing
       l → p          p → q           q → r

    Here:
    - q = index where decreasing part ends
    - p = index where decreasing part begins


    ll ans = LLONG_MIN;

    for (int q = 1; q < n - 1; q++)
    {

        // Must have decreasing ending at q
        if (nums[q] >= nums[q - 1])
            continue;

        // To make sure decreasing segment length is greater than equal to 2
        if (decLeft[q] == nums[q])
            continue;

        // Must be increasing after q
        if (nums[q] >= nums[q + 1])
            continue;

        // finding the start of ending phase
        int p = q - 1;
        while (p > 0 && nums[p] < nums[p - 1])
            p--;

        if (p == 0)
            continue; // As no space for left increasing would be there

        // Just a check to make sure if left part actually incrases
        if (nums[p] <= nums[p - 1])
            continue;

        ll leftSum = incLeft[p - 1];
        ll decSum = decLeft[q]; // Decreasing sum ending at q
        ll rightSum = incRight[q + 1];

        ll total = leftSum + decSum + rightSum;

        ans = max(ans, total);
    }
    return ans == LLONG_MIN ? 0 : ans;
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {0, -2, -1, -3, 0, 2, -1};
    cout << maxSumTrionic(nums) << endl;

    return 0;
}