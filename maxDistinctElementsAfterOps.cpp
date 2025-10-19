#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

int maxDistinctElements(vector<int> &nums, int k)
{
    // add an integer in range [-k,k] to the element
    // return the max possible number of distinct elements in nums after performing the operations

    int n = nums.size();
    // unordered_map<int,int>freq;
    // for(auto&x:nums)freq[x]++;

    // if(k==0)return freq.size();

    // int diff = 2*k+1;

    // //if ony 1 type of numbers are present
    // //if(freq.size() == 1)return diff;

    // // ans = max(freq,diff) for all
    // int ans = 0;

    // for(auto&num : freq)
    // {
    //     int an = min(num.second, diff);
    //     ans+=an;
    // }
    // return ans;

    sort(nums.begin(), nums.end());

    int count = 0; // counts maximum distinct numbers

    int next = INT_MIN; // next smalles number we can assign to maintain distinctness

    for (int num : nums)
    {
        // Range upto which this number can go
        int low = num - k;
        int high = num + k;

        if (high < next)
            continue;

        int assigned = max(next, low);

        // updating next available number the upcoming number
        next = assigned + 1;

        count++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5};
    cout << maxDistinctElements(nums, 2) << endl;

    return 0;
}
