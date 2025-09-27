#include <bits/stdc++.h>
using namespace std;

int minOps(int k, vector<int> &arr)
{
    int n = arr.size();

    // we are given k -> New MEX
    // we can choose element at any index and replace it with any number within(0,n)

    // we have to calculate how many such operations would be needed

    // count numbers with 0 frequency from 0 till mex-1

    int missing = 0;
    int kcount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == k)
            kcount++;
    }

    for (int i = 0; i < k; i++)
    {
        if (arr[i] != i)
        {
            missing++;
        }
    }
    return max(missing, kcount);
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << minOps(k, arr) << endl;
    }
    return 0;
}
