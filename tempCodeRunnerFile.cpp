#include<bits/stdc++.h>
using namespace std;

long long maximumProfit(vector<int>& prices, int k)
{

    /*/prices[i] is the price of stock

    We can make atmost k transactions : 
    Normal : Buy on day i, sell on later day j : Profit = prices[j] - prices[i]

    Short : Sell on day i, then buy back on later day j: Profit = prices[i] - prices[j]


    Return the max total profit we can earn by making atmost k transactions

    State : [t,0]->Free 
            [t,1]-> Holding long posi
            [t,2]->Holding short posi

    We cannot start new trasnsaction until the current one is finished


    */

    int n = prices.size();

    const int NEG_INF = -1e9;

    vector<vector<int>>dp(k+1,vector<int>(3,NEG_INF));

    //intitiallising day 0

    dp[0][0] = 0; //do nothing
    dp[0][1] = -prices[0]; //buy on day 0
    dp[0][2] = prices[0]; // short sell on day 0

    //Process each day
    for(int i = 0; i < n ;i++)
    {
        vector<vector<int>>newdp = dp;//Copying previous day states

        for(int t = 0; t<= k;t++)
        {
            //Option 1 : Stay free
            newdp[t][0] = dp[t][0];


            //Option 2:  Sell long or buy short 
            if(t>0)
            {
                //close long posi, sell today
                newdp[t][0] = max(newdp[t][0], dp[t-1][1] + prices[i]);

                //close short posi, and buy back today
                newdp[t][0] = max(newdp[t][0], dp[t-1][2] - prices[i]);


                //State 1: Long

                //Option 1: Keep Holding long 
                newdp[t][1] = dp[t][1];

                //Buy today if you were free
                newdp[t][1] = max(newdp[t][1], dp[t][0] - prices[i]);
    
                //State 2: Short

                //Option 1: Keep holding short
                newdp[t][2] = dp[t][2];

                //Option 2 : Short sell today if free
                newdp[t][2] = max(newdp[t][2], dp[t][0] + prices[i]);
            }
            dp = newdp;
        }
    }
    int ans = 0;
    for(int t = 0;t<=k;t++)
    {
        ans = max(ans,dp[t][0]);   
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>prices = {1,7,9,8,2};
    cout<<maximumProfit(prices,2)<<endl;
    
    return 0;
    
}