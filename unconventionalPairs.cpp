#include <bits/stdc++.h>
using namespace std;

int minValue(vector<int> &arr)
{
    // petty must divide no.of partipants into exactly n/2 pairs ,and each index can be included in no more than one pair

    // maxDifference among all pairs is minimized

    // find min possible value of this max difference

    // find the max possible difference between any two numbers

    sort(arr.begin(), arr.end());

    int maxDiff = 0;
    for (int i = 1; i < arr.size(); i += 2)
    {
        int diff = abs(arr[i - 1] - arr[i]);
        maxDiff = max(diff, maxDiff);
    }
    return maxDiff;
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

        cout << minValue(arr) << endl;
    }
    return 0;
}