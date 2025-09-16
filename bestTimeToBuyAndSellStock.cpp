#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
    
  //  7,1,5,3,6,4

    //price[i] is the price of given stock

    // we have to choose the day with least price and then look for the day afterwards with highest price

    // we have to find two days such that 1st day has least digit and digit after that is max and if no such conditioni is found return 0

    int minPrice = prices[0]; 
    int maxProfit = 0; 


    for(int i = 1; i<prices.size(); i++)
    {
       // updating minPrice if the current price is lower
        if(prices[i] < minPrice) // if the given price is less than the intMax
        {
            minPrice = prices[i]; 
        }
        
        int profit = prices[i] - minPrice;

        if(profit  > maxProfit)
        {
            maxProfit = profit;

        }
    }
    return maxProfit;
}

int main()
{
    vector<int>prices = {7,1,5,3,6,4};

    int ans = maxProfit(prices);

    cout<<"Profit:  "<<ans<<endl;

    return 0;

}