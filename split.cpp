#include <bits/stdc++.h>
using namespace std;

int maxi(vector<int> &arr)
{
    int n = arr.size();

    unordered_map<int, int> freq;
    int O = 0, E = 0;

    for (auto &num : freq)
    {
        if (num.second % 2 == 1)
            O++;

        else
            E++;
    }

    int ans = O + 2 * min(E, n - O);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        for (auto &x : a)
            cin >> x;

        cout << maxi(a) << endl;
    }

    return 0;
}