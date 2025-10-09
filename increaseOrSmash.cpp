#include <bits/stdc++.h>
using namespace std;

int minOps(vector<int> arr)
{
    unordered_set<int> s;

    int n = arr.size();

    if (n == 1)
        return 1; // only one increae is sufficient if we have only num

    for (auto &num : arr)
    {
        s.insert(num);
    }
    int m = s.size();

    return 2 * m - 1;

    // choose integer x and increase all elements of array by x

    // OR for each i he either replaces ai with 0 or leaves

    // find the minOps he required to get that target array
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
