#include <bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int> &nums)
{
    /*
    Construct an array fo length n : ans[i] and ans[i] + 1 has bitwise OR equal to nums[i]

    //If not possible value put -1 there

    And we needed to maximise each value of ans[igb    ]
    */

    // x Or x+1 = Y

    int n = nums.size();

    for (int &x : nums)
    {
        // To store min valid value of j
        int res = -1;

        int power = 1; // Represents power of 2

        while ((x & power) != 0)
        {
            // Removing current power of 2 from x
            res = x - power;
            power <<= 1; // Move to next higher power
        }
        x = res;
    }
    return nums;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {2, 3, 5, 7};
    vector<int> ans = minBitwiseArray(nums);

    for (auto &an : ans)
        cout << an << " ";

    cout << endl;

    return 0;
}