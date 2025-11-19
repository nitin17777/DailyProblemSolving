#include <bits/stdc++.h>
using namespace std;

int findFinalValue(vector<int> &nums, int original)
{
    // if given original value is found , multiply it by 2

    // return the final value of original
    int n = nums.size();

    set<int> st(nums.begin(), nums.end());

    while (st.count(original))
        original *= 2;

    return original;
}

int main()
{
    vector<int> nums = {5, 3, 6, 1, 12};

    cout << findFinalValue(nums, 3) << endl;

    return 0;
}
