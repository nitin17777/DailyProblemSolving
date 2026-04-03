#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

/*

The given recurrence simplifies to C[n][k] = 2
So problem becomes : For each query k print 2^k % MOD 

*/


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    
    vector<int>n(t),k(t);;
    for(auto & x:k)cin>>x;

    for(auto& x:k)cin>>x;

    //to get to know the wht might be our largest power
    int maxk = *max_element(k.begin(),k.end());

    //Pre computing powers of 2

    vector<int>power(maxk + 1,1);
    for(int i = 1;i<=maxk;i++)
    {
        power[i] = (2LL * power[i-1])%MOD;
    }

    //Returning answer for each query
    for(int x :k)cout<<power[x]<<endl;

    return 0;
}