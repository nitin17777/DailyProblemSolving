#include <iostream>
#include <vector>

using namespace std;

string solve(vector<int> &perm)
{
    // an array is bad if and only if: 1 <= i <= n-4
    // Either ascending or descending

    // we have total of n turns, at each turn either remove leftmost or rightmost elements

    // choose which element to remove in each turn such that resulting array is good
    int n = perm.size();

    string ans;
    int l = 0, r = n - 1;

    for (int turn = 1; turn <= n; turn++)
    {
        bool takeleft;

        // If odd turn, take the min from left and right side
        if (turn % 2 == 1)
            takeleft = perm[l] < perm[r];

        // else take the max
        else
            takeleft = perm[l] > perm[r];

        if (takeleft)
        {
            ans.push_back('L');
            l++;
        }
        else
        {
            ans.push_back('R');
            r--;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> perm(n);
        for (auto &x : perm)
            cin >> x;

        cout << solve(perm) << endl;
    }
    return 0;
}
