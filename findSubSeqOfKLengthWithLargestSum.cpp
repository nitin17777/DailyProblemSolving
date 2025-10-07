#include <bits/stdc++.h>

using namespace std;

vector<int> maxSubsequence(vector<int> &nums, int k)
{
    // find subsequence of k length that has the largest sum
    int n = nums.size();

    vector<pair<int, int>> numWithIndex;

    for (int i = 0; i < n; i++)
    {
        numWithIndex.push_back({nums[i], i});
    }

    // sort by value :descending

    sort(numWithIndex.begin(), numWithIndex.end(), [](auto &a, auto &b)
         {
             return a.first > b.first;
         });

    vector<pair<int, int>> topK(numWithIndex.begin(), numWithIndex.begin() + k);

    sort(topK.begin(), topK.end(), [](auto &a, auto &b)
         { return a.second < b.second; });

    vector<int> ans;
    for (auto &an : topK)
    {
        ans.push_back(an.first);
    }
    return ans;
}

int main()
{

    vector<int> nums = {2, 1, 3, 3};

    vector<int> ans = maxSubsequence(nums, 2);

    for (auto &an : ans)
    {
        cout << an << " ";
    }
    cout << endl;

    return 0;
}