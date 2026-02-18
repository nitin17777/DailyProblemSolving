#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int> &nums)
{
    int n = nums.size();

    // pick any one number nums[i] and delete it to earn nums[i] points
    map<int, int> freq;
    for (auto &x : nums)
        freq[x]++;

    vector<pair<int, int>> v(freq.begin(), freq.end());

    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.second < b.second; // ascending by value
         });

    int score = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i - 1])
        {
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nm = {3, 4, 2};
    cout << deleteAndEarn(nm) << endl;

    return 0;
}