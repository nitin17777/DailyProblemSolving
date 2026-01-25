#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums, int k)
{

    if (k == 1)
        return 0;

    int n = nums.size();

    sort(nums.begin(), nums.end());

    int mini = INT_MAX;

    for (int i = 0; i + k - 1 < n; i++)
    {
        int mn = nums[i + k - 1] - nums[i];
        mini = min(mn, mini);
    }
    return mini;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {9, 4, 1, 7};
    cout << minimumDifference(nums, 2) << endl;
    return 0;
}