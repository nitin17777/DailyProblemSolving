#include<bits/stdc++.h>
using namespace std;
#define ll long long

int numberOfStableArrays(int zero, int one, int limit)
{
    const int MOD = 1e9+7;

    vector<vector<vector<int>>>memo(zero+1,vector<vector<int>>(one+1, vector<int>(2,-1)));

    //memo(z,o,last) ->z,o = Number of remaining zeros and ones last = lat placed bit

    function<int(int, int, int)>dp = [&](int z,int o,int last) -> int
    {
        //Base case: When no zeros left
        if(z==0)
        {
            //Only ones remain -> Valid only if streak <= limit
            if(last == 0 || o > limit)return 0;

            return 1;
        }

        //Base case: when no one left
        if(o == 0)
        {
            if(last == 1 || z >limit)return 0;

            return 1;
        }

        //Return memoized result if already computed
        if(memo[z][o][last] != -1)
        {
            return memo[z][o][last];
        }

        ll result = 0;

        if(last == 0)
        {
            result = (dp(z-1,o,0) + dp(z-1,o,1))%MOD;

            if(z>limit)
            {
                result = (result - dp(z-limit-1,o,1)+MOD)%MOD; 
            }
        }

        else
        {
            //We will place a 1 at the end
            result = (dp(z,o-1,0) + dp(z,o-1,1))%MOD;
            if(o>limit)
            {
                result = (result - dp(z,o-limit-1,0) + MOD)%MOD;
            }
        }
        return memo[z][o][last] = result;
    };

    //Arrays ending in 0 or 1
    return (dp(zero,one,0) + dp(zero,one,1))%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<numberOfStableArrays(1,1,2)<<endl;

    return 0;
}