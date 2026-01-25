#include <bits/stdc++.h>
using namespace std;

// Unable to understand this much clearly fr, will solve it much effeciently after a month ig.
double largestSumOfAverages(vector<int> &nums, int k)
{
    int n = nums.size();
    /*
    We can partition array into atmost k adjacent subarray
    Score of partition = sum of average of each

    Return the max score we can achieve of all possible partition


    sort(nums.begin(),nums.end());
    int ans = 0;
    int i = n-1;

    //1 2 3 9 9
    while(k > 1)
    {
        ans+=nums[i];
        i--;
        k--;
    }

    int after = 0;
    for(int j = 0;j<i;j++)
    {
        after += nums[i];
    }
    ans +=after/2;

    return ans;
}*/

    // Building prefix arr so as to compute avergae of any interval easily
    vector<double> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // dp[i] = nax score we can get by participating first i elements
    vector<double> dp(n + 1, 0.0);

    // Base case:If allowed only one partition then best we can do first i elements is to take their average
    for (int i = 1; i <= n; i++)
    {
        dp[i] = prefix[i] / i;
    }

    // Try increasing partition from 2 to k, each iteration adds one more possibe cut

    for (int part = 2; part <= k; part++)
    {
        for (int i = n; i >= part; i--)
        {
            for (int x = part - 1; x < i; x++)
            {
                double avg = (prefix[i] - prefix[x]) / (i - x);
                dp[i] = max(dp[i], dp[x] + avg);
            }
        }
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {9, 1, 2, 3, 9};
    cout << largestSumOfAverages(nums, 3) << endl;
    return 0;
}