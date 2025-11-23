#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    // An aray is called balanced if intger x occurs exactly once

    /*

    Min number of elements to delete to make array balanced

    */

    unordered_map<int, int> freq;
    for (auto &x : arr)
        freq[x]++;

    // a number can occur only no.of times equal to it

    int cnt = 0;
    for (auto &num : freq)
    {
        int number = num.first;
        int frequency = num.second;

        int diff = frequency - number;

        if (frequency < number)
            cnt += frequency;

        else
            cnt += diff;
    }
    return cnt;
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
