#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;



//NOT FULLY UNDERSTOOD THIS SOLUTION, HAVE TO LOOK BACK IT AGAIN
ll power(ll a,ll b)
{
    ll res = 1;

    while(b)
    {
        if(b&1)res = res*a %MOD;

        a = a*a %MOD;
        b>>=1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);
        for(auto &x:a)cin>>x;

        //Alternating sum of sequence must be 0, determine how many subsequences are there

        //Every value must be selected even number of times to have net effect 0


        // if some value occurs k times, there are exactly 2^k-1 ways to have valid choices


        set<int>st;

        bool hasMinusOne = false;

        for(auto&x:a)
        {
            if(x==-1)hasMinusOne = true;
            else st.insert(x);
        }


        int d = st.size()+hasMinusOne;

        int l = 0;

        for(auto x:st)
        {
            if(st.count(x+1))l++;
        }

        ll ans = power(2,n-d);

        if(hasMinusOne)
        {
            ans = ans * (l+1) %MOD;
        }

        cout<<ans<<'\n';
    }

    return 0;
}