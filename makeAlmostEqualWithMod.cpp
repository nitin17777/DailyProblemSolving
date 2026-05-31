#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll>&a,int n)
{
    //Find k such that only distinct elements are there in array at last
    for (ll k = 2; k <= (1LL << 60); k <<= 1)
    {
        set<ll>s;

        for(ll x:a)s.insert(x % k);

        if(s.size() == 2)return k;
    }
    return -1;
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

        vector<ll>a(n);
        for(auto& x:a)cin>>x;

        cout<<solve(a,n)<<endl;    
    }

    return 0;
}