#include <bits/stdc++.h>
using namespace std;

bool canWin(vector<int> &arr)
{
    // choose an index i such that ai >= mx and set mx to ai then set ai to 0
    int n = arr.size();

    // to count how many times value at i appears
    vector<int> count(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // checking if value has odd frequency
    for (int i = 1; i <= n; i++)
    {
        if (count[i] % 2 == 1) // if any value appears odd time ,alice wins
            return true;
    }
    return false;
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
        cout << (canWin(arr) ? "YES" : "NO") << endl;
        ;
    }

    return 0;
}