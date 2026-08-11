#include<bits/stdc++.h>
#define ll long long
using namespace std;

 int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find sum of longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        // Find smallest missing integer >= sum
        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(sum))
            sum++;

        return sum;
    }
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,2,3,2,5};
    cout<<missingInteger(nums)<<endl;

    return 0;
}