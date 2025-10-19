#include <bits/stdc++.h>
using namespace std;

int score(vector<int> arr)
{
    // find the minimum MEX out of all multiset

    // we have to partition arr into some multisets such that MEX of all of them is same

    // no matter how we will divide all mutisets,minimum mex would be the MEX of given array

    // So we just need to find the mex of array  :)

    int n = arr.size();
    vector<bool> present(n + 1, false);

    for (int x : arr)
        if (x <= n)
            present[x] = true;

    for (int i = 0; i <= n; i++)
    {
        if (!present[i])
            return i;
    }

    /* o(nlog n) Time complexity

    sort(arr.begin(), arr.end());
    int mex = 0;

    for (int x : arr)
    {
        if (mex == x)
            mex++;
        else if (x > mex)
            break;
    }
    return mex;
    */
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
        cout << score(arr) << endl;
    }
    return 0;
}