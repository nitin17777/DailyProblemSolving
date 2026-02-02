#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long minimumCost(vector<int> &nums, int k, int dist)
{
    int n = nums.size();

    /*

    dist = how far apart each subarray can get

    Cost of subarray = value of it's first element

    Divide nums into k disjoint subarrays such that

    Return the min possible sum of cost of these subarrays

    */
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {1, 3, 2, 6, 4, 2};
    cout << minimumCost(nums, 3, 3) << endl;
    return 0;
}