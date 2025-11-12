#include <bits/stdc++.h>
using namespace std;

int gcdAll(vector<int> &nums)
{
    int g = nums[0];

    for (int x : nums)
    {
        g = __gcd(g, x);
    }
    return g;
}

int minOperations(vector<int> &nums)
{
    /*Replace nums[i] or nums[i+1] with their gcd value

    we have to return  the min num of ops required to convert all the elements of given array to 1,return -1 if it is impossible

    ALGO:
        select two consecutive nums, as they will have gcd  = 1 for sure

        So if we have two consecutive nums we can convert with ops = nums.size(),else reutrn -1

    */
    int n = nums.size();
    // if full array does not have gcd = 1 then->Impossible
    if (gcdAll(nums) != 1)
        return -1;

    int ones = count(nums.begin(), nums.end(), 1);
    if (ones > 0)
        return n - ones;

    if (find(nums.begin(), nums.end(), 1) != nums.end())
        return n - 1;

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int g = nums[i];

        for (int j = i; j < n; j++)
        {
            g = __gcd(g, nums[j]);

            if (g == 1)
            {
                ans = min(ans, j - i + 1);
                break;
            }
        }
    }
    // ans - 1 => operations required to make that subarray into one

    return (ans - 1) + (n - 1); // as soon as we got one '1',  we can make other elements 1 also in n-1 ops
}

int main()
{
    vector<int> nums = {935839, 59074, 1, 1, 1, 539890, 135036, 248163, 519664, 794201, 915143, 353146, 764742, 1, 1, 1, 33204, 661690, 1, 1, 414294, 1, 778895, 1, 1, 357151, 1, 645007, 707404, 599671, 1, 120017, 220478, 69724, 1, 1, 1, 604942, 543935, 1, 1};

    cout << minOperations(nums) << endl;
    return 0;
}
