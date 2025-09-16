#include<bits/stdc++.h>
using namespace std;

long long mostPoints(vector<vector<int>>& ques)
{
    int n = ques.size();

    vector<long long>dp(n+1,0);

    for(int i = n-1; i>=0; i--)
    {
        int points = ques[i][0];
        int skip = ques[i][1];

        long long solve;

        if((skip + i+1) <n)
        {
            solve = points + dp[i+1+skip];
        }

        else{
            solve = points;

        }

        long long skipQues= dp[i+1];
        dp[i] = max(solve,skipQues);
    }
    return dp[0];
}

