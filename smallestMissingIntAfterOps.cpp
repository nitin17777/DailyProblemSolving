#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findSmallestInteger(vector<int> &nums, int value)
{
    // in one operation we can add or subtract value from any element of nums

    // return the maximimum MEX of nums after applying mentioned operation any number of times

    // counting how many numbers fall into cretain remainder category
    unordered_map<int, int> count;
    for (int x : nums)
    {
        int r = ((x % value) + value) % value; // handling negatives
        count[r]++;
    }

    int i = 0;

    while (true)
    {
        int r = i % value; /// remainder needed

        if (count[r] > 0)
            count[r]--;

        else
            return i;
        i++;
    }
}

int main()
{
    vector<int> nums = {1, -10, 7, 13, 6, 8};
    cout << findSmallestInteger(nums, 5) << endl;

    return 0;
}