#include <bits/stdc++.h>
using namespace std;

// int maxNum(vector<int> &arr, int idx)
// {
//     int i = 1;
//     int maxNum = arr[0];

//     while (i < idx)
//     {
//         maxNum = max(maxNum, arr[i]);
//         i++;
//     }
//     return maxNum;
// }

int minCost(vector<int> &arr)
{
    int n = arr.size();

    vector<int> pre(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = max(pre[i - 1], arr[i]);
    }

    // awesome if : If i odd -> bi < b i+1 holds
    //  If i is even -> bi > bi+1 holds
    // elements at even position are always greater than elements at odd positions

    // b1<b2>b3<b4 simply

    // we can do 2 opertaions:1=>select i and do ai = max(a1,a2,...ai)
    //  2=>or select i and decrease ai by 1

    // it would be beneficial to apply operation 1 on even indices ,so that they could become bigger

    // and another on odd indices so as to make them smaller

    // Determine min number of times we need to do operation 2 to make given array awesome

    // As we will decrease the odd indexed elements later, we should apply operation 2 to every even indexed elements first

    int cost = 0;

    for (int i = 0; i < n; i += 2)
    {
        int diff = -1;

        if (i > 0)
        {
            diff = max(diff, arr[i] - pre[i - 1]);
        }

        if (i < n - 1)
        {
            diff = max(diff, arr[i] - pre[i + 1]);
        }
        cost += diff + 1;
    }

    // As we will decrease the odd indexed elements later, we should apply operation 2 to every even indexed elements first
    /*for (int i = 1; i < n; i += 2)
    {
        int maxi = maxNum(arr, i);
        if (maxi > arr[i])
        {
            arr[i] = maxi;
        }
    }

    // Now we are done with increasing work and just have to primarily focus on decreasing

    // Taking care of edge case
    if (arr[0] > arr[1])
    {
        cost += arr[0] - arr[1];
    }

    // now doing the decrement work
    for (int i = 2; i + 1 < n; i += 2)
    {
        int val = max(0, arr[i] - min(arr[i - 1], arr[i + 1]) + 1);

        cost += val;
    }*/
    return cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
        cout << minCost(arr) << endl;
    }
    return 0;
}
