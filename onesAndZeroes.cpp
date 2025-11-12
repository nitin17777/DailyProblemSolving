#include <iostream>
#include <vector>

using namespace std;

pair<int, int> counts(string s)
{
    int oC = 0, zC = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            zC++;
        else
            oC++;
    }
    return make_pair(oC, zC);
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    // return the lenght of the largest subset of strs such that there are at most m  0s and n 1s in the subset

    // count zeroes and ones of every string and jus place them in theri respective indices

    vector<pair<int, int>> record;
    for (auto x : strs)
    {
        record.push_back(counts(x));
    }

    // now we have zero count and one count packed at each index

    // now search for the largest subset consisting of m 0s and n 1s

    // we will do this by using dp

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // dp[i][j] = max number of strings we can pick if we have atmost i zeros and at most j ones available

    for (auto [one, zeros] : record)
    {
        for (int i = m; i >= zeros; i--)
        {
            for (int j = n; j >= one; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - one] + 1);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(strs, 5, 3) << endl;
    return 0;
}
