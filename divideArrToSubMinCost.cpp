#include <bits/stdc++.h>
using namespace std;

int minimumCost(vector<int> &nums)
{

    int ans = nums[0]; // Because this index will always be head

    // find the smallest and 2nd smallest num
    vector<int> temp(nums.begin() + 1, nums.end());

    sort(temp.begin(), temp.end());

    ans += temp[0] + temp[1];

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {10, 3, 1, 1};

    cout << minimumCost(nums) << endl;
    return 0;
}