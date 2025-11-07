#include <bits/stdc++.h>
using namespace std;

vector<int> findXSum(vector<int> &nums, int k, int x)
{
    // Count occurences => Keep only top x elements in the array, and if two nums have same frequency element with bigger value is considered

    // calculate the sum of this array

    int n = nums.size();
    if (x < 2)
        return accumulate(nums.begin(), nums.end(), 0);

    vector<int> ans(n - k + 1);

    int l = 0;
    for (int r = k - 1; r < n; r++)
    {
        unordered_map<int, int> freq;
        for (auto &x : nums)
            freq[x]++;

        vector<pair<int, int>> v(freq.begin().freq.end());

        sort(v.begin(), v.end, [](auto &a, auto &b)
             { return a.second < b.second; });
    }

    for (int i = 0; i < x; i++)
    {
    }
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};

    vector<int> ans = findXSum(nums, 6, 2);

    for (auto &x : nums)
        cout << x << " ";

    cout << endl;

    return 0;
}
