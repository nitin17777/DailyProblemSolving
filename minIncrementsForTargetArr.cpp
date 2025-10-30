#include <bits/stdc++.h>
using namespace std;

int minNumberOperations(vector<int> &target)
{
    // we have an "initial" array with size of target array initiallised with 0

    // In one operation, we can choose any subarray from initial and increment each value by 1

    // return min ops to form target arr

    // ALGO: Whenver the successive number increases, we need an extra operation equal to the positive difference, and if successive number is decreased , we will not need any increment, so we just need: target[0] + (total increment throughout the array)

    int n = target.size();
    int inc = 0;

    for (int i = 1; i < n; i++)
    {
        if (target[i] > target[i - 1])
        {
            inc = inc + target[i] - target[i - 1];
        }
    }
    return target[0] + inc;
}

int main()
{
    vector<int> target = {1, 2, 3, 2, 1};
    cout << minNumberOperations(target) << endl;

    return 0;
}