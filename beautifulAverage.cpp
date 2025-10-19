#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxVal(vector<int> &arr)
{
    // find max possible average value of any subarray of array a

    int n = arr.size();
    sort(arr.begin(), arr.end());
    return arr[n - 1];
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
        cout << maxVal(arr) << endl;
    }
    return 0;
}