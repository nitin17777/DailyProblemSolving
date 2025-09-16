#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

    int numberOfWays(int n, int x)
    {
        //return the minimum number of ways n can be expressed as sum of xth power of unique positive integers
        int MOD = 1e9+7;

        //Generating all xth powers <=n

        for(ll i = 0;;++i)
        {
            ll value = 1;

//Calculating i^x using repeated multiplication
            for(int t =0;t<x;++t)
            {
                val *= i;

                if(val>n)break;

            }
            if(val>n)break;
            powers.push_back((int)val);
        }

        int m = powers.size();//number of pwers generated


        //Now making memoisation table
        //dp[idx][rem]  = number of ways to form rem using power from index idx and initialise with -1 to denote uncomputed states
        

        vector<vector<ll>dp(m+1, vector<ll>(n+1,-1));





    }


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    int x= 2; 

    int ans = numberOfWays(n,x);

    cout<<ans<<endl;

    return 0;
    
}
