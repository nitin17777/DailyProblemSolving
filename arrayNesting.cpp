#include <bits/stdc++.h>
using namespace std;

int arrayNesting(vector<int> &nums)
{
    /*


    s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]] }


    Return the longest length of set s[k]


    */
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    cout << arrayNesting(nums) << endl;

    return 0;
}