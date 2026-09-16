#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Not able to understnad this solution fully though
static const ll MOD = 1000000007;
ll power(ll a,ll b)
{
    ll res = 1;

    while(b>0)
    {
        //if current bit of b is 1 
        if(b&1)res = (res*a)%MOD;

        a = (a*a)%MOD;

        //Move to the next bit
        b>>=1; //equivalent to b/2
    }
    return res;
}

int numberOfSets(int n, int k)
{

    /* 
        Drawn segments must not overlap
        So basiscally we want to find how many different ways can I choose exactly k lines such that each segments covers at least 2 points and no segment overlaps

        for k segments , we need 2k endpoints

    */

    int N = n+k-1;
    int R = 2*k;

    ll numer = 1;
    ll denom = 1;

    for(int i =1;i<=R;i++)
    {
        numer = numer*(N-R+i)%MOD;
    }

    for(int i=1;i<=R;i++)
    {
        denom = denom *i % MOD;
    }

    //We need numerator/denominator
    //And division under modulo is done using modular inverse

    //denominator ^(-1) = denominator^(MOD-2)
    ll inverseDenom = power(denom,MOD-2);

    return numer* inverseDenom %MOD;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<numberOfSets(4,2)<<endl;

    return 0;
}