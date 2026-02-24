#include <bits/stdc++.h>
using namespace std;

#define ll long long

string solve(vector<int> &a, int k)
{

    int n = a.size();

    // ith box has ai apples inside

    // Predict the winner of the game

    // Tom goes first

    /*Conditions:

    if no valid box exists -> Current player loses
    If after the move max(a) - min(a) > k holds -> Then current player loses

    4-1 = 3 => 3-1 = 2 Jerry
    3-1 = 2 => 2-1 = 1 Tom
    2-1 = 1 => 1-1 = 0 Tom

    */

    // If sum is odd - > Jerry will be the last one to make a valid move.
    // else Tom will win

    ll sum = accumulate(a.begin(), a.end(), 0LL);

    sort(a.begin(), a.end());

    a[n - 1]--;

    sort(a.begin(), a.end());

    if (a[n - 1] - a[0] > k || sum % 2 == 0)
        return "Jerry";

    else
        return "Tom";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a, k) << endl;
    }
    return 0;
}