#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int trap(vector<int> &height)
{
    // we have to calculate how much water it can trap after raining

    // Algo: Water trapped at index depends upon : min(maxLeft[i], max(Right[i] - height[i]))
    int n = height.size();
    if (n == 0)
        return 0;

    // left and right for each index
    vector<int> left(n), right(n);

    // left max for each index
    left[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }

    // right max for each index
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }

    int water = 0;

    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - height[i];
    }
    return water;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << endl;

    return 0;
}
