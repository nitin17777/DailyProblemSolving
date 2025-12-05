#include <bits/stdc++.h>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{

    /*

    1 day Pass : costs[0]
    7 day Pass : costs[1];
    30 day Pass : cost[2];


    Return the min number of dollars need to travel every day in given list of days

    */
    vector<int> dp(367, 0);

    vector<bool> travel(366, false);

    for (int d : days)
        travel[d] = true;

    for (int i = 365; i >= 1; i--)
    {
        if (!travel[i])
        {
            dp[i] = dp[i + 1];
        }

        else
        {

            int cost1 = costs[0] + dp[min(366, i + 1)];
            int cost7 = costs[1] + dp[min(366, i + 7)];
            int cost30 = costs[2] + dp[min(366, i + 30)];

            dp[i] = min({cost1, cost7, cost30});
        }
    }
    return dp[days[0]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    cout << mincostTickets(days, costs) << endl;

    return 0;
}