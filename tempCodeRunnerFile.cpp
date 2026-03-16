#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


int solve(vector<ll>&a,int k)
{
    int n = a.size();

    //Inone operation, wec can selcet any contiguous sub and insert the sum of this subarray anywhere in the array


    //find the max possible sum of the array after k operations

    ll s = 0;
    for(int x : a)s+=x;

    // max subarray sum x
    ll curr = 0,mx = 0;
    for(int i =0;i<n;i++)
    {
        curr = max(curr+a[i], 0LL);
        mx = max(mx,curr);
    }

    //Computing 2^k %MOD

    ll pow2 = 1;
    for(int i = 0;i<k;i++)
    {
        pow2 = pow2 * 2 % MOD;
    }

    s = (s % MOD + MOD)%MOD;//For handling negative

    ll ans = (s + mx* (pow2 - 1) %MOD + MOD)%MOD;

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
        int n,k;
        cin>>n>>k;

        vector<ll>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,k)<<endl;

    }
    return 0;
}