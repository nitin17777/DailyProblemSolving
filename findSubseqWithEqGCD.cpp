#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

int subsequencePairCount(vector<int>& a)
{

    //gcd of s1 == s2 , return total number of pairs of such subsequence


    //this is the max possible gcd value
    int mx = *max_element(a.begin(),a.end());

    // dp[i][j] = number of ways after processing some prefix ,i = gcd of seq1 and j = gcd of seq2
    vector<vector<int>>dp(mx+1,vector<int>(mx+1,0));



    //since both subsequence are empty at first
    dp[0][0] = 1;

    for(int x:a)
    {

        //choice 1 is to simply ignroe this element
        vector<vector<int>>ndp = dp;

        for(int g1 = 0;g1<=mx;g1++)
        {
            for(int g2 = 0;g2<=mx;g2++)
            {
                if(dp[g1][g2] == 0) continue;

                //on inserting x into new subsequence -> gcd becomes gcd(oldGCD,x)
                //if seq is empty currently then gcd  = x.
                int ng1 = (g1 == 0)?x:gcd(g1,x);

                int ng2 = (g2 == 0)?x:gcd(g2,x);


                //Choice 2 is to put x in seq1 and seq2 remains unchanged

                ndp[ng1][g2] += dp[g1][g2];

                if(ndp[ng1][g2] >= MOD)ndp[ng1][g2] -= MOD;


                //Choice 3 is to put x in seq2 and seq1 remains unchanged

                ndp[g1][ng2] += dp[g1][g2];

                if(ndp[g1][ng2] >= MOD)ndp[g1][ng2] -= MOD;
            }
        }

        //Moving to next element
        dp.swap(ndp);

    }

    //Now we want states where gcd(g1) == gcd(g2)
    ll ans = 0;
    for(int g = 1;g<=mx;g++)
    {
        ans+=dp[g][g];
        ans%=MOD;
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a={1,2,3,4};
    cout<<subsequencePairCount(a)<<'\n';

    return 0;
}