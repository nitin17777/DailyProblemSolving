#include <bits/stdc++.h>
using namespace std;

int minRemoval(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1)
        return 0;

    /*
    An array is balanced if value of it's max element is at most k times the min element -> y<=2x

    Return the min number of elements to remove so that array is balanced
    We can delete any number of elements from the  array


    */

    if (nums.size() == 2)
    {
        if (nums[0] * k < nums[1])
            return 1;
    }

    sort(nums.begin(), nums.end());
    int cnt = INT_MAX;
    int l = 0, r = 0;

    while (r < n)
    {
        int mini = nums[l];
        int maxi = nums[r];

        if ((long long)mini * k >= maxi)
        {
            int rem = n - (r - l) - 1;
            cnt = min(cnt, rem);
        }

        else
            l++;

        r++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {2, 1, 5};
    cout << minRemoval(a, 2) << endl;
    return 0;
}