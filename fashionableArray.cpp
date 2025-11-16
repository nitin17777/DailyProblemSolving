#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    // first and last element should both be of same parity

    // if not,move from smallest element until we get to match the parity of largest digit and vice versa

    int mn = arr[0], mx = arr[n - 1];

    if ((mn + mx) % 2 == 0)
        return 0;

    // First i where a[i] has different parity from n
    int left = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] % 2 != arr[0] % 2)
        {
            left = i;
            break;
        }
    }
    int right = n;
    for (int i = 1; i < n; i++)
    {
        if (arr[n - 1 - i] % 2 != arr[n - 1] % 2)
        {
            right = i;
            break;
        }
    }

    return min(left, right);
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

        for (auto &x : arr)
            cin >> x;
        cout << solve(arr) << endl;
    }
    return 0;
}
