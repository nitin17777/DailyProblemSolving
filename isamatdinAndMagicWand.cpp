#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool areSame(ll a, ll b)
{
    if (a % 2 == b % 2)
        return true;
    else
        return false;
}

vector<ll> correct(vector<ll> &nums)
{
    // numbers can only be swapped if both have different parity

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((nums[i] > nums[j]) && !areSame(nums[i], nums[j]))
            {
                swap(nums[i], nums[j]);
            }
        }
    }
    return nums;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        vector<ll> ans = correct(nums);

        for (auto &an : ans)
        {
            cout << an << " ";
        }
        cout << endl;
    }
    return 0;
}
