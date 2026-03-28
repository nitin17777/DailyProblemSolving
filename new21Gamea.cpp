#include<bits/stdc++.h>
using namespace std;

double new21Game(int n, int k, int maxPts)
{
    /*
    Alice draws numbers while she has less than k points
    And she gains integer number of points in each draw from [1,maxPts]
    She stops drawing numbers when she gets more than k points
    Return probability that she has n or fewer points

    */

    if (n >= k + maxPts - 1) return 1.0;

    if(k == 0)return 1.0;

    //dp[i] = probability of getting exactly i points
    vector<double>dp(n+1,0.0);
    
    dp[0] = 1.0;//since initially 0 points are there only


    double windowSum = 1.0, res = 0.0;

    for(int i = 1;i<=n;i++)
    {
        //dp[i] is average of previous maxPts states
        dp[i] = windowSum / maxPts;

        if(i<k)
        {
            windowSum += dp[i];
        }

        else
        {
            res += dp[i];
        }

        //Removing elements going out of the window
        if(i-maxPts >= 0)windowSum -= dp[i-maxPts];
    }

    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<new21Game(10,1,10)<<endl;

    return 0;
}