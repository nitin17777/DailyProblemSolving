#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long getDescentPeriods(vector<int> &prices)
{

    int n = prices.size();

    /*

    Smooth des period ->one or more contiguous days such that price on each day is lower than price of preceding day by exactly 1

    Also, the first day is exempted


    Return the number of smooth descent periods
    */

    // return the max subarray such that difference bw consecutive elements is at max 1

    ll len = 1;
    ll cnt = 1;

    for (int r = 1; r < n; r++)
    {

        if (prices[r - 1] - prices[r] == 1)
        {
            len++;
            // Each time an index satisfies this condition, it contributes r-l+1
        }
        else
        {
            len = 1;
        }
        cnt += len;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> prices = {3, 2, 1, 4};

    cout << getDescentPeriods(prices) << endl;

    return 0;
}