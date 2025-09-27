#include <iostream>
#include <vector>

using namespace std;

int minOps(vector<int> &arr)
{
    // at one time select only index and increase element at index by 1
    // goal is to make the overall product of all elements in array stirctly with min ops possible

    // so we need even number of -1 and no 0 should be there

    int minusCount = 0, zeroCount = 0, minOps = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
            minusCount++;
        if (arr[i] == 0)
            zeroCount++;
    }

    if (minusCount % 2 != 0)
    {
        minOps += 2;
    }

    minOps += zeroCount;
    return minOps;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << minOps(arr) << endl;
    }
    return 0;
}
