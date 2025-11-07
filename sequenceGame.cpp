#include <bits/stdc++.h>
using namespace std;

bool can(vector<int> &nums, int target)
{
    // we can perform the operation: select two adjacent nums ai and a i+1,and replace them with any integer : min(ai, ai+1) <= y<= max(ai,ai+1)
    int minEle = *min_element(nums.begin(), nums.end());
    int maxEle = *max_element(nums.begin(), nums.end());

    if (minEle <= target && target <= maxEle)
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
        int n, target;
        cin >> n;

        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;

        cin >> target;

        cout << (can(nums, target) ? "YES" : "NO") << endl;
    }
    return 0;
}