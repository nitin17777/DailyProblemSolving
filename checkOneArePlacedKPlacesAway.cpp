#include <bits/stdc++.h>
using namespace std;

bool kLengthApart(vector<int> &nums, int k)
{
    // check if all 1s are placed atleast 'k' places awasy

    int n = nums.size();

    int zcnt = 0, oneCount = 0;

    // after every '1' count number of zero, and as soon as '1' comes, check if num of zeroes >= k,if no return

    // we need to igore the first presence of '1' in the beginning

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            zcnt++;

        if (nums[i] == 1 && oneCount == 0) // pass in this case
        {
            oneCount++;
            zcnt = 0; // Reset here too
            continue;
        }

        if (nums[i] == 1 && oneCount >= 1)
        {
            if (zcnt < k)
                return false;

            else
            {
                zcnt = 0; // reset zero count
                oneCount++;
            }
        }
    }
    return true;
}

int main()
{

    vector<int> nums = {1, 0, 0, 1, 0, 1};
    cout << (kLengthApart(nums, 2) ? "true" : "false") << endl;

    return 0;
}
