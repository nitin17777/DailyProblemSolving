#include <bits/stdc++.h>
using namespace std;

int longestBalanced(vector<int> &nums)
{
    int n = nums.size();

    // Balanced if number of even == number of odd in a given subarray

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> evenFreq;
        unordered_map<int, int> oddFreq;

        int disE = 0;
        int disO = 0;

        for (int j = i; j < n; j++)
        {
            if (nums[j] % 2 == 0)
            {
                evenFreq[nums[j]]++;

                if (evenFreq[nums[j]] == 1)
                    disE++;
            }

            else
            {
                oddFreq[nums[j]]++;

                if (oddFreq[nums[j]] == 1)
                    disO++;
            }

            if (disE == disO)
                ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {2, 5, 4, 3};
    cout << longestBalanced(nums) << endl;
    return 0;
}