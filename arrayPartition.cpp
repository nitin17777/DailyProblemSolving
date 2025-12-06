#include <bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int> &nums)
{
    int n = nums.size();

    // Group these nums into n pairs such that sum of min(ai,bi) for all i is maximised

    // Return maximised sum 1 2 2 5 6 6

    sort(nums.begin(), nums.end());

    int sum = 0;

    for (int i = 0; i < n; i += 2)
    {
        sum += nums[i];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {1, 4, 3, 2};
    cout << arrayPairSum(nums) << endl;

    return 0;
}