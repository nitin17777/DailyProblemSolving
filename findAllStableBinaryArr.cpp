#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

int numberOfStableArrays(int zero, int one, int limit)
{
    //Stable if: number of occurences of 0 and 1 are exactly numZero and numOne respectively   
            // + no more than 'limit' consecutive elements should be there

    //We have to return total number of stable binary arrays

    /* dp[z][o][last][len]
    last = last placed element
    len = current consecutive streak length of 'last'

    */
   int maxLen = min(limit,max(zero,one));

    static ll dp[205][205][2][205];
    memset(dp,0,sizeof(dp));


    //starting the array with a single 0
    if(zero > 0)dp[1][0][0][1] = 1;

    //Starting the array with single one
    if(one > 0)dp[0][1][1][1] = 1;

    //Now iterating over zeros
    for(int z = 0; z<=zero;z++)
    {
        //now over ones
        for(int o = 0;o<=one;o++)
        {
            //Now ovet the last placed element
            for(int last = 0;last<2;last++)
            {
                //Now over the curent streak length
                for(int len = 1;len <= maxLen;len++)
                {
                    ll curr = dp[z][o][last][len];

                    //Checking if this current state was never reached or not
                    if(curr == 0)continue;

                    //Trying to place a zero now
                    if(z<zero)
                    {
                        //If last placed element was also 0
                        if(last == 0)
                        {
                            //We can extend the streak only if  <= limit
                            if(len+1 <=maxLen)
                            {
                                dp[z+1][o][0][len +1] = (dp[z+1][o][0][len+1] + curr)%MOD;
                            }
                        }
                        
                        else
                        {
                            //Streak resets to 1
                            dp[z+1][o][0][1] = (dp[z+1][o][0][1] + curr)%MOD;
                        }
                    }

                    //Trying to place a one now
                    if(o<one)
                    {
                        if(last == 1)
                        {
                            //Extending the streak if allowed
                            if(len + 1 <= maxLen)
                            {
                                dp[z][o+1][1][len+1] = (dp[z][o+1][1][len+1] +curr)%MOD;
                            }
                        }
                        else
                        {
                            //AS last was 0, so streak wil reset
                            dp[z][o+1][1][1] =  (dp[z][o+1][1][1] + curr) %MOD; 
                        }
                    }

                }
            }
        }
    }

    ll ans = 0;
    //Final ans : Sum of all the ways that used exactly zero zeors and one ones without taking care of streak lenght and ending element
    for(int last = 0;last<2;last++)
    {
        for(int len = 1;len<=maxLen;len++)
        {
            ans = (ans+ dp[zero][one][last][len])%MOD;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<numberOfStableArrays(1,1,2)<<endl;

    
    return 0;
}