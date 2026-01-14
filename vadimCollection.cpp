#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    /*
    ith digit from left is at least 10-i  in the beautiful phone number

    Rearrange its digit such that result is smallest possible beautiful phone number
    */

    vector<int> cnt(10, 0);
    for (auto &x : s)
        cnt[x - '0']++;

    string ans = "";

    for (int i = 1; i <= 10; i++)
    {
        int req = 10 - i;

        for (int j = req; j <= 9; j++)
        {
            if (cnt[j] > 0)
            {
                ans += char('0' + j);
                cnt[j]--;
                break;
            }
        }
    }
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
        string n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}