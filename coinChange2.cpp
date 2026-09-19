#include<bits/stdc++.h>
#define ll long long
using namespace std;

int change(int amount, vector<int>& coins)
{

    // int g = 0;

    // for(int coin:coins)
    // {
    //     g=gcd(g,coin);
    // }


    // if(amount%g != 0)return 0;

    //Return the number of coins that make up that amount else return 0


    //dp[i] = Number of ways to make amount i
    vector<unsigned int>dp(amount+1,0);

    //Since only way to have 0 money is choose nothing 
    dp[0] = 1;

    for(auto&coin:coins)
    {
        for(int curr = coin;curr<=amount;curr++)
        {
            dp[curr]+=dp[curr-coin];
        }
    }
    return dp[amount];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>coins = {1,2,5};

    cout<<change(5,coins)<<endl;


    return 0;
}