#include <bits/stdc++.h>
using namespace std;
#define ll long long

int countPartitions(vector<int> &nums)
{
    // Return the number of partitions where diff bw sum of left and right subarrays is even

    // For every index find left and right prefix sum

    int n = nums.size();
    vector<int> ls(n, 0), rs(n, 0);

    ls[0] = nums[0];
    rs[n - 1] = 0;

    // leftSum inluding the digit
    for (int i = 1; i < n; i++)
    {
        ls[i] = nums[i] + ls[i - 1];
    }

    // rightSum excluding the digit
    for (int i = n - 2; i >= 0; i--)
    {
        rs[i] = nums[i + 1] + rs[i + 1];
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if ((ls[i] - rs[i]) % 2 == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {10, 10, 3, 7, 6};

    cout << countPartitions(nums) << endl;

    return 0;
}