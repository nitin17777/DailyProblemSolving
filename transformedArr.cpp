#include <bits/stdc++.h>
using namespace std;

vector<int> constructTransformedArray(vector<int> &nums)
{
    /*
    1-> If nums[i] > 0 ->

    For each index ,move nums[index] forward and assign the value of that index at that place

    1 2

    */
    int n = nums.size();
    int i = 0;
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            res[i] == 0;
            continue;
        }

        int idx = ((i + nums[i]) % n + n) % n;

        res[i] = nums[idx];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {3, -2, 1, 1};
    vector<int> ans = constructTransformedArray(arr);
    for (auto &an : ans)
        cout << an << " ";

    cout << endl;

    return 0;
}