#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minimumDistance(vector<int>& nums)
{
     unordered_map<int, vector<int>> mp;

    // Store indices for each value
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    int ans = INT_MAX;

    for (auto &it : mp) {
        vector<int> &v = it.second;

        // Need at least 3 indices
        if (v.size() >= 3) {
            // Try consecutive triplets
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}



      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,2,1,1,3};

    cout<<minimumDistance(nums)<<endl;


    return 0;
}