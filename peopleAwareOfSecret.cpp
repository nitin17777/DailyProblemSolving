#include<iostream>
#include<vector>
using namespace std;


int peopleAwareOfSecret(int n, int delay, int forget)
{
    const int MOD = 1e9 +7;


    //we have to return the number of people who know the secret at the end of day n


    //Person will forget the secret after FORGET days after discovering it

    vector<long long>dp(n+1,0);
    dp[1] = 1; // Only 1 person knows the secret on day1 

    long long sharing = 0;//count of people who can share the secret on current day

    for(int day = 2; day<=n;day++)
    {
        //Adding people who start sharing today
        if(day - delay >= 1)
        sharing = (sharing  + dp[day-delay] + MOD)%MOD;

        if(day -forget >=1)
        sharing  = (sharing - dp[day - forget] + MOD) %MOD;

        dp[day] = sharing;

    }

    long long ans= 0;
    for(int day = n-forget+1; day<=n;day++)
    {
        if(day >= 1)
        {
            ans = (ans + dp[day]) %MOD;

        }
    }

    return ans;
}

using namespace std;

int main()
{

    cout<<peopleAwareOfSecret(6,2,4)<<endl;
    return 0;
}
