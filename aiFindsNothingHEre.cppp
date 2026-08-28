#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 998244353;

ll power(ll p)
{
    ll ans = 1;
    ll base = 2;
    
    while(p>0)
    {
        // Include current power of 2 if this bit of p is set
        if(p&1)ans = ans * base % MOD;

        //Move to next power of 2
        base = base*base %MOD;

        p>>=1;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,m,r,c;
        cin>>n>>m>>r>>c;
    
        //n rows and m columns

        //Clean matrix if: bitwise XOR sum of elements in each submatrix is 0

        //Calculate number of such clean matrices

        //Every r*c submatrix must have xor equal to 0

        ll freeCells = n*m - (n-r+1)*(m-c+1);

        //every free cell can either be 0 or 1 so we have 2^freeCells choices
        cout<<power(freeCells)<<'\n';
    }
    return 0;
}