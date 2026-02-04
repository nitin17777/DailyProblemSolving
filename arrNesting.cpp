#include <bits/stdc++.h>
using namespace std;

int arrayNesting(vector<int> &nums)
{
    int n = nums.size();

    // Return the longest length of set s[k]

    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        // If already part of some cycle ->SKIP
        if (nums[i] == -1)
            continue;

        int len = 0;
        int curr = i;

        while (nums[curr] != -1)
        {
            int next = nums[curr];

            nums[curr] = -1;
            curr = next;
            len++;
        }
        maxLen = max(maxLen, len);
    }
    return maxLen;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    cout << arrayNesting(nums) << endl;
    return 0;
}