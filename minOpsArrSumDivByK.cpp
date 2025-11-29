#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    // we can replace a number num by num-1
    int sum = 0;
    for (auto num : nums)
        sum += num;
    return sum % k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {3, 9, 7};
    cout << minOperations(nums, 5) << endl;

    return 0;
}