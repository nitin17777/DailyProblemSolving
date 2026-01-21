#include <bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int> &nums)
{

    int n = nums.size();

    /*
    This array consists of n prime numbers

    ans[i] OR ans[i+1] = nums[i]

    Each value of ans should be minimised

    put -1 if not possible
    */
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